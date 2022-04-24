#pragma once
#include "Obstacles.hpp"
#include <vector>
#include <iostream>

using namespace std;

class SquareObstacle : public Obstacles
{
private:
public:
    int pos = 1;

    SquareObstacle();

    void fly();
    Obstacles *getObstacles(SDL_Rect) override;
};
