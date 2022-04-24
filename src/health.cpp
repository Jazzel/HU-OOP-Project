#include "health.hpp"
#include <iostream>

//#include "drawing.hpp"
using namespace std;

// Drawing::gameAssets = loadTexture("assets/game-assets.png");

void Health::updateHealth(Obstacles *obstacle)
{
    SquareObstacle square;
    WallObstacle wall;
    BombObstacle bomb;
    HealthObstacle healthbump;

    if (typeid(*obstacle).name() == typeid(square).name())
    {
        Mix_PlayChannel(-1, Drawing::gCrash, 0);
        health -= 25;
    }
    else if (typeid(*obstacle).name() == typeid(wall).name())
    {
        Mix_PlayChannel(-1, Drawing::gCrash, 0);
        health -= 50;
    }
    else if (typeid(*obstacle).name() == typeid(bomb).name())
    {
        Mix_PlayChannel(-1, Drawing::gExplode, 0);
        health = 0;
    }
    else if (typeid(*obstacle).name() == typeid(healthbump).name())
    {
        Mix_PlayChannel(-1, Drawing::gHealth, 0);
        if (health != 100)
        {
            health += 25;
        }
    }
    else
    {
        health -= 25;
    }
}

void Health::displayHealth()
{
    SDL_Rect src, mover;
    if (health == 100)
    {
        src = {88, 1534, 2045, 176};
        mover = {30, 30, 580, 50};
    }
    else if (health == 75)
    {
        src = {88, 1290, 1584, 176};
        mover = {30, 30, 450, 50};
    }
    else if (health == 50)
    {
        src = {87, 1056, 1125, 176};
        mover = {30, 30, 320, 50};
    }
    else if (health == 25)
    {
        src = {48, 837, 666, 176};
        mover = {30, 30, 190, 50};
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &src, &mover);
}

Health::Health()
{
    health = 100;
}