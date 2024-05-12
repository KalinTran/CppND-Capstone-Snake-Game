# CPPND: Capstone Snake Game

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

# Rubric Items Matched
## New Features
* Display score and snake size when game is over
* Press `Q` to quit the game
* Press `ESC` to Pause/Resume the game
* Can set snake starting speed
### 1
### `Object Oriented Programming - One or more classes are added to the project with appropriate access specifiers for class members.`
To meet this requirement, a `PlatformGame` class was created (inside `platformgame.h`) to hold information about the system platform. The class uses the member functions `getPlform` and `printPlform` to get and print detect platform.

### 2
### `Object Oriented Programming - Class constructors utilize member initialization lists.`
> All class members that are set to argument values are initialized through member initialization lists.
`platformgame.h` (line 11)  the default argument for the private variable `platformisUsed(line 17)` is a null string which is set within the class's initiaziation list.

### 3
### `Object Oriented Programming - Classes abstract implementation details from their interfaces.`
> All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
The [C++ Guide by Google](https://google.github.io/styleguide/cppguide.html#Function_Comments) was used to for any needed documentation. An example can be found within `metagame.h` (line 16) above the function declaration of `getPlatform` where a simple comment is used to describe what the function does. Also, a function comment can be found in `snake.h` line 25.

### 4
### `Loops, Functions, I/O - The project accepts user input and processes the input.`
> The project accepts input from a user as part of the necessary operation of the program.
The user has the option to select the starting speed of the snake. A Game class member function `UpdateStartSpeed` 

### 5 `Loops, Functions, I/O - The project demonstrates an understanding of C++ functions and control structures`
whole project organized with proper use of functions and flow of data.

### 6
### ` Memory Management - The project makes use of references in function declarations`
method HandleInput() in controller.h:10, use pass by ref and Run() in game.h:15
### `Memory Management - The project uses destructors appropriately. `
~Renderer() in renderer.h:12
### `The project uses smart pointers instead of raw pointers. `
snake` is a `shared_ptr` in `game.h:25`
