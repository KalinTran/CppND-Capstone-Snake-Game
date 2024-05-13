#ifndef FOOD_H_
#define FOOD_H_

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
    void setGameRunning(bool running);
    FoodPhase getCurrentPhase();
private:
    FoodPhase _currentPhase;
    bool _isGameRunning;
    void cyclePhases();
    std::mutex _mutex;
protected:
    std::thread t;
};

#endif