#ifndef GAME_H
#define GAME_H

#include <memory>
#include <random>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void UpdateStartSpeed();
  bool IsPaused() const ;
  void Pause() ;
  void Resume() ;

private:
  std::shared_ptr<Snake> snake;
  SDL_Point food;
  SDL_Point bonusfood;
  std::mt19937 engine;
  std::random_device dev;

  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  int numbNormalEat{0};
  bool _running{true};
  bool _paused{false};
  void PlaceFood();
  void PlaceBonusFood();
  void Update();
};

#endif