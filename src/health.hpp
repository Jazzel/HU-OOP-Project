#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include "Asset.hpp"
#include "SquareObstacle.hpp"
#include "WallObstacle.hpp"
#include "BombObstacle.hpp"
#include "drawing.hpp"
#include "HealthObstacle.hpp"
//#include "drawing.hpp"

using namespace std;

class Health : public Asset
{
private:
    int health = 100;

public:
    void updateHealth(Obstacles *obstacle);
    void displayHealth();
    inline int getHealth() { return health; }

    Health();
};