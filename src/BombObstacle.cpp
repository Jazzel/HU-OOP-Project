#include "BombObstacle.hpp"

Obstacles *BombObstacle::getObstacles(SDL_Rect mover)
{
    BombObstacle *asset = new BombObstacle();
    asset->src = {1048, 59, 312, 369};

    asset->mover = mover;

    // cout << obstacles.size() << "Square triggered !!" << endl; // they are   
    // issuing 

    return asset;
}

void BombObstacle::fly()
{

    if (mover.x <= 630)
    {
        mover.x -= 5;
        mover.y += 10;
    }
    else if (mover.x > 670)
    {
        mover.x += 5;
        mover.y += 10;
    }
    else
    {
        mover.y += 10;
    }
    mover.h += 5;
    mover.w += 5;
}

BombObstacle::BombObstacle()
{
}
