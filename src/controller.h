#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Game;

class Controller {
public:
  void HandleInput(bool &running, Snake &snake, Game &game) const;

private:
  bool IsDirectionKeyPressed(SDL_Keycode key) const;
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif