#include "HealthObstacle.hpp"

Obstacles *HealthObstacle::getObstacles(SDL_Rect mover)
{
    HealthObstacle *asset = new HealthObstacle();
    asset->src = {2157, 1182, 317, 318};

    asset->mover = mover;

    return asset;
}

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
HealthObstacle::HealthObstacle()
{
}
