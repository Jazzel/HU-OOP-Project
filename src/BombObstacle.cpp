// ? header files
#include "BombObstacle.hpp"

/**
 * ? @brief getobstacle()
 * * dynamically creates a bomb obstacle using polymorphism
 * * defines the assets's src rect and assigns mover
 *
 * ? @param
 *
 * * SDL_RECT - mover, where the object has to be created
 *
 * ! return
 * * obstacles * - a pointing reference to obstacle which is created
 */

Obstacles *BombObstacle::getObstacles(SDL_Rect mover)
{
    BombObstacle *asset = new BombObstacle();
    asset->src = {1048, 59, 312, 369};

    asset->mover = mover;

    return asset;
}

/**
 * ? @brief fly()
 * * if the object is either on left or right side then it travels further in that direction
 * * otherwise only the y coordinate increaes
 * * the obstcale is enlarged by incrementing its height and width
 */
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
    mover.h += 3;
    mover.w += 3;
}
/**
 * ? @brief BombObstacle()
 * * an empty constructor for bomb obstacle creation
 */
BombObstacle::BombObstacle()
{
}
