#include <iostream>
#include <chrono>
#include "food.h"

Food::Food() 
{
    _currentPhase = FoodPhase::fresh;
    _isGameRunning = true;
    t = std::thread(&Food::cyclePhases, this);
}

void Food::cyclePhases() 
{
    int cycle_duration = 5000;
    auto last_time = std::chrono::high_resolution_clock::now();

    while (_isGameRunning) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        auto current_time = std::chrono::high_resolution_clock::now();
        auto time_diff = current_time - last_time;
        if (std::chrono::duration_cast<std::chrono::milliseconds>(time_diff).count() > cycle_duration) {
            std::unique_lock<std::mutex> uLock(_mutex);
            if (_currentPhase == FoodPhase::fresh) _currentPhase = FoodPhase::rotten;
            else _currentPhase = FoodPhase::fresh;
            uLock.unlock();
            last_time = std::chrono::high_resolution_clock::now();
        }
    }
}
FoodPhase Food::getCurrentPhase() {
    std::lock_guard<std::mutex> uLock(_mutex);
    return _currentPhase;
}
void Food::setGameRunning(bool running) {
    _isGameRunning = running;
}