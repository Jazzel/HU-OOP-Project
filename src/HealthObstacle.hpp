#pragma once
#include "Obstacles.hpp"
#include <vector>
#include <iostream>

using namespace std;

class HealthObstacle : public Obstacles
{
private:
public:
    HealthObstacle();
    Obstacles *getObstacles(SDL_Rect) override;
    void fly();
};