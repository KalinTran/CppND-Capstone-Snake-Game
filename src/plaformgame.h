#ifndef PLATFORMGAME_H
#define PLATFORMGAME_H

#include <iostream>
#include <string>
#include "SDL.h"

class PlatformGame
{
public:
    PlatformGame() : platformisUsed(std::string()) { platformisUsed = getPlform(); }

    std::string getPlform();
    void printPlform();

private:
    std::string platformisUsed;
};

std::string PlatformGame::getPlform()
{
    const char *lPlatform = SDL_GetPlatform();
    std::string p(lPlatform);
    platformisUsed = p;
    return p;
};

void PlatformGame::printPlform()
{
    if (platformisUsed != "")
        std::cout << "Platform Detected: " << platformisUsed << std::endl;
    else
        std::cout << "None Platform Detected." << std::endl;
}

#endif