#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(new Snake(grid_width, grid_height)),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  while (_running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(_running, *snake, *this);
    Update();
    if (foodstore->HasFood())
    {
        food = foodstore->perchures();
    }
    renderer.Render(*snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

SDL_Point Game::NewFood()
{
    int x, y;
    while (true) {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake->SnakeCell(x, y)) {
            break;
        }
   }
    SDL_Point food{x, y};
    return food;
}

void Game::UpdateStartSpeed() { snake->SetStartingSpeed(); }

void Game::PlaceFood() {
  SDL_Point food = NewFood();
  std::future<void> ftr = std::async(std::launch::async,
                                      &Foodstore<SDL_Point>::reload,
                                      foodstore,
                                      std::move(food));
  ftr.wait();
}

void Game::Update() {
  if (Game::IsPaused())
  {
      return;
  }
  if (!snake->alive) 
  {
    _running = false;
    return;
  }
  snake->Update();

  int new_x = static_cast<int>(snake->head_x);
  int new_y = static_cast<int>(snake->head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake->GrowBody();
    snake->speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake->size; }
bool Game::IsPaused() const { return _paused; }
void Game::Pause() { _paused = true; }
void Game::Resume() { _paused = false; }
