#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include <thread>
#include <mutex>

enum FoodPhase {
    fresh,
    rotten
};

class Food : public SDL_Point {
public:
    Food();
    ~Food();

    FoodPhase getCurrentPhase();
    void setGameRunning(bool running);

protected:
    std::thread t;

private:
    FoodPhase _currentPhase;
    bool _isGameRunning;
    void cycleThroughPhases();
    std::mutex _mutex;
};

#endif