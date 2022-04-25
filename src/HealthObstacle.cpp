//? header files
#include "HealthObstacle.hpp"
/**
 * ? @brief getobstacle()
 * * dynamically creates a health obstacle using polymorphism
 * * defines the assets's src rect and assigns mover
 *
 * ? @param
 *
 * * SDL_RECT - mover, where the object has to be created
 *
 * ! return
 * * obstacles * - a pointing reference to obstacle which is created
 */
Obstacles *HealthObstacle::getObstacles(SDL_Rect mover)
{
    HealthObstacle *asset = new HealthObstacle();
    asset->src = {2157, 1182, 317, 318};

    asset->mover = mover;

    return asset;
}
/**
 * ? @brief fly()
 * * if the object is either on left or right side then it travels further in that direction
 * * otherwise only the y coordinate increaes
 */
void HealthObstacle::fly()
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
    // mover.h += 5;
    // mover.w += 5;
}
/**
 * ? @brief HealthObstacle()
 * * an empty constructor for health obstacle creation
 */
HealthObstacle::HealthObstacle()
{
}
