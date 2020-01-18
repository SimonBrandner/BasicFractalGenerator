#ifndef GAME
#define GAME

#include "Game.hpp"

Game::Game(int length, int mapSizeX, int mapSizeY, bool * q) : MapSizeX(), MapSizeY(), quit()
{
    // Variables
    MapSizeX = mapSizeX;
    MapSizeY = mapSizeY;
    quit = q;
}
    // Variables

std::vector<Pixel> Game::getChangedPixels()
{
    std::vector<Pixel> changedPixels;
    
    for (int i = 0; i < DrawnPixels.size(); i++)
    {
        changedPixels.push_back(DrawnPixels[i]);    
    }

    DrawnPixels.clear();

    return changedPixels;
}

void Game::passInput(std::string pressedKey)
{
    if (pressedKey == "none"){return;}
    // Set variable based on pressed key
}

void Game::update()
{
    if(Location.x >= MapSizeX && Location.y >= MapSizeY) {}
    else
    {
        if (Location.x >= MapSizeX)
        {
            Location.x = 0; 
            Location.y++;
        }
        else
        {
            Location.x++;
        }

        std::complex<double> numberToTest(1./(MapSizeX/2) * Location.x - 1, 1./(MapSizeX/2) * Location.y - 1);

        Color color = Game::sequenceGeneration(numberToTest, MaxIterations, Tolerance);

        DrawnPixels.push_back({Location.x, Location.y, color.red, color.green, color.blue, 100});
    }
}

Color Game::sequenceGeneration(std::complex<double> numberToTest, int maxIterations, float tolerance)
{
    std::complex<double> z = numberToTest;
    std::complex<double> zNew;
    std::complex<double> one(1., 0.);
    std::complex<double> two(cos(2./3. * M_PI), sin(2./3. * M_PI));
    std::complex<double> three(cos(4./3. * M_PI), sin(4./3. * M_PI));

    for (int i = 0; i < maxIterations; i++)
    {
        zNew = Game::newtonMethod(z);

        if (std::abs(zNew - z) < tolerance)
        {
            if(std::abs(zNew - one) < tolerance)
            {
                return {255, 0, 0};
            }
            else if (std::abs(zNew - two) < tolerance)
            {
                return {0, 255, 0};
            }
            else if (std::abs(zNew - three) < tolerance)
            {
                return {0, 0, 255};
            }
        }
        z = zNew;
    }

    return {255, 255, 255};
}

std::complex<double> Game::newtonMethod(std::complex<double> z)
{   
    std::complex<double> zero(0., 0.);
    if (z == zero)
    {
        return std::complex<double>(1., 0.);
    } 
    
    std::complex<double> twoThirds(2./3., 0.);
    std::complex<double> oneThird(1./3., 0.);
    std::complex<double> result();
    return twoThirds * z + oneThird / std::pow(z, 2.);
}

#endif
