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

protected:
    int frame;

    vector<Obstacles *> obstacles;
    // string type;
public:
    Obstacles();
    Obstacles(SDL_Rect srcRect);
    ~Obstacles();

    virtual Obstacles *getObstacles() = 0;
    void grow();
    void draw();
};
