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
    void setGameRunning(bool running);
    FoodPhase getCurrentPhase();
private:
    FoodPhase _curPhase;
    bool _isGameRunning;
    void cyclePhases();
    std::mutex _mtx;
protected:
    std::thread t;
};

#endif