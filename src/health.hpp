#pragma once
#include <iostream>
#include <SDL.h>
#include "Vehicle.hpp"
#include "SquareObstacle.hpp"
#include "WallObstacle.hpp"
#include "BombObstacle.hpp"
#include "HealthObstacle.hpp"
//#include "drawing.hpp"

using namespace std;

class Health : public ScreenObject
{
private:
    int health = 100;

public:
    void updateHealth(Obstacles *obstacle);
    void displayHealth();
    inline int getHealth() { return health; }

    Health();
};