#include <iostream>
#include <chrono>
#include "food.h"

Food::Food() {
    // Initialize the food phase and the state of the game
    _currentPhase = FoodPhase::fresh;
    _isGameRunning = true;

    // Start food phase toggler function in another thread
    t = std::thread(&Food::cycleThroughPhases, this);
}

Food::~Food() {
    t.join();
}

// Toogles the food phase according to given time
void Food::cycleThroughPhases() {
    // Cycle time to toggle food phase in ms. It is 5000 by default.
    int cycle_duration = 5000;

    // Save the current time to calculate elapsed time
    auto last_time = std::chrono::high_resolution_clock::now();
    
    // Toggle food phase while the game is running
    while (_isGameRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // Calculate the elapsed time
        auto current_time = std::chrono::high_resolution_clock::now();
        auto time_diff = current_time - last_time;

        // If elapsed time longer than the given duration toggle the food phase
        if (std::chrono::duration_cast<std::chrono::milliseconds>(time_diff).count() > cycle_duration) {
            // Lock the mutex to avoid data races
            std::unique_lock<std::mutex> uLock(_mutex);
            
            // Toggle food phase
            if (_currentPhase == FoodPhase::fresh) _currentPhase = FoodPhase::rotten;
            else _currentPhase = FoodPhase::fresh;
            
            uLock.unlock();

            // Update last time
            last_time = std::chrono::high_resolution_clock::now();
        }
    }
}

// Get current food phase
FoodPhase Food::getCurrentPhase() {
    std::lock_guard<std::mutex> uLock(_mutex);
    return _currentPhase;
}

// Change the status of the game
void Food::setGameRunning(bool running) {
    _isGameRunning = running;
}