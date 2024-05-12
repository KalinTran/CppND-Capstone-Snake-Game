#ifndef METAGAME_H
#define METAGAME_H

#include <iostream>
#include <string>
#include "SDL.h"

class MetaGame
{
public:
    MetaGame() : platformUsed(std::string()) { platformUsed = getPlatform(); }

    std::string getPlatform();
    void printPlatform();

private:
    std::string platformUsed;
};

std::string MetaGame::getPlatform()
{
    const char *platform = SDL_GetPlatform();
    std::string p(platform);
    platformUsed = p;
    return platformUsed;
};

void MetaGame::printPlatform()
{
    if (platformUsed != "")
        std::cout << "Platform Detected: " << platformUsed << std::endl;
    else
        std::cout << "No System Platform Detected." << std::endl;
}

#endif