#pragma once
#include "drawing.hpp"
#include <SDL.h>
#include <vector>
#include <iostream>

using namespace std;

class Obstacles
{
public:
    SDL_Rect src, mover;

public:
    Obstacles();
    ~Obstacles();

    bool deleteObjects();
    virtual Obstacles *getObstacles(SDL_Rect) = 0;
    virtual void fly();
};
