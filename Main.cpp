#include "Engine.hpp"
#include "Game.hpp"

#include <string>
#include <iostream>
#include <curses.h>
#include <ctime>

int main()
{
    // Variables
    int screenSizeX = 1024;
    int screenSizeY = 512;
    int scaleX = 1;
    int scaleY = 1;
    float gameSpeed = 100000;
    bool quit = false;
    // Variables

    Engine engine(screenSizeX, screenSizeY, scaleX, scaleY, gameSpeed, &quit); // Initialize engine
    
    while(!quit)
    {
        engine.update(); // Run engine update member function
    }

    return 0;
}