cmake_minimum_required(VERSION 3.7)
project(SDL2Test)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Create the executable
add_executable(SnakeGame ${SOURCES})

# Link SDL2 libraries
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})
