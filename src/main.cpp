#include <iostream>
#include "renderer.h"
#include <condition_variable>
#include "plaformgame.h"
#include "controller.h"
#include "game.h"
#include <thread>
#include <mutex>
#include <chrono>

// std::mutex mtx;
// std::condition_variable con_var;
// std::chrono::time_point<std::chrono::high_resolution_clock> gstartTime;

// void time_end_print()
// {
//   std::unique_lock<std::mutex> lck(mtx);
//   con_var.wait(lck );
//   auto gendTime = std::chrono::high_resolution_clock::now(); 
//   auto duration = (gendTime - gstartTime);
//   auto duration_micro = std::chrono::duration_cast<std::chrono::seconds>(duration);

//   std::cout << "Playing game time: " << duration_micro.count() << " second" << std::endl;
// }

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
 
  PlatformGame lStats;
  lStats.printPlform();
  // std::thread t(time_end_print);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.UpdateStartSpeed();
  // gstartTime = std::chrono::high_resolution_clock::now();

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  // con_var.notify_all();
  // t.join();
  // std::chrono::seconds duration(2); //delay 2s

  return 0;
}