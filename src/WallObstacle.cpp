#include "WallObstacle.hpp"

Obstacles *WallObstacle::getObstacles(SDL_Rect mover)
{
    WallObstacle *asset = new WallObstacle();
    int random = 1;
    if (random == 1)
    {
        asset->src = {1748, 119, 287, 811};
    }
    else
    {
        asset->src = {2243, 166, 306, 843};
    }
    asset->mover = mover;
    if (random != 1)
    {
        cout << "true  ------\n";
        asset->mover.x == 700;
        asset->mover.y == mover.y;
        asset->mover.w == mover.w;
        asset->mover.h == mover.h;
    }
    // else
    // {
    // }

    return asset;
}

void WallObstacle::fly()
{
    if (mover.x <= 650)
    {
        mover.x -= 5;
        mover.y += 10;
    }
    else if (mover.x > 650)
    {
        mover.x += 5;
        mover.y += 10;
    }
    mover.h += 20;
    mover.w += 10;
}

WallObstacle::WallObstacle()
{
}
