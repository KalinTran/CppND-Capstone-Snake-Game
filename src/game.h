#ifndef GAME_H
#define GAME_H

#include <memory>
#include <random>
#include <iostream>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <mutex>
#include <condition_variable>
#include <deque>
template <class Food>
class Foodstore
{
private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<Food> _shelf;

public:
    Foodstore() {};
    bool HasFood() {return _shelf.size() > 0;}
    Food perchures() {
        std::unique_lock<std::mutex> uLock(_mutex);
        _cond.wait(uLock, [this] { return !_shelf.empty(); }); 

        Food food = std::move(_shelf.front());
        _shelf.pop_front();

        return food;
    }
    void reload(Food food) {
        std::lock_guard<std::mutex> uLock(_mutex);
        std::cout << "   New Food (" << food.x << ", " << food.y << ") add to the shelf" << '\n';
        _shelf.emplace_back(std::move(food));
        _cond.notify_one();
    }
};

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
  std::shared_ptr<Foodstore<SDL_Point>> foodstore;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  bool _running{true};
  bool _paused{false};
  void PlaceFood();
  SDL_Point NewFood();
  void Update();
};

#endif