#ifndef ENGINECLASS
#define ENGINECLASS

#include "SDL.h"
#include <iostream>

#include "Game.hpp"
#include "Main.hpp"

class Engine
{
public:
    // Member functions
    Engine(int, int, int, int, float, bool *);
    void update();
    // Member functions
private:
    // Member functions
    void renderFrame(std::vector<Pixel>);
    std::string handleSDLEvent();
    // Member functions

    // Variables
    SDL_Event sdlEvent;
    SDL_Window *sdlWindow;
    SDL_Renderer *sdlRenderer;
    bool * quit;
    Game * game;
    unsigned int loopNumber = 0;
    float gameSpeed; // Number between 0 - 1  
    // Variables
};

#endif
