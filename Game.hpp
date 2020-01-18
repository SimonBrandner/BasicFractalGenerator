#ifndef GAMECLASS
#define GAMECLASS

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <complex>

#include "Main.hpp"

class Game
{
public:
    Game(int, int, int, bool *);
    std::vector<Pixel> getChangedPixels();
    
    void passInput(std::string);
    void update();
private:
    static std::complex<double> newtonMethod(std::complex<double>);
    static Color sequenceGeneration(std::complex<double>, int, float);

    int MapSizeX;
    int MapSizeY;

    std::vector<Pixel> DrawnPixels;

    int MaxIterations = 100;
    float Tolerance = std::pow(10, -3);
    Coordinates Location = {0, 0};
    

    bool * quit;
};

#endif
