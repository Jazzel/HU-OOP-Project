//? header files
#include "WallObstacle.hpp"
/**
 * ? @brief getobstacle()
 * * dynamically creates a wall obstacle using polymorphism
 * * using if statements checks which wall should be created and hence src rect is defined
 * * assets's mover is assigned with mover from arguements
 *
 * ? @param
 *
 * * SDL_RECT - mover, where the object has to be created
 *
 * ! return
 * * obstacles * - a pointing reference to obstacle which is created
 */
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

    return asset;
}
/**
 * ? @brief fly()
 * * if the object is either on left or right side then it travels further in that direction
 * * the height and width of the wall is increased hence to create a 3d perspective
 */
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
    mover.h += 10;
    mover.w += 5;
}
/**
 * ? @brief WallObstacle()
 * * an empty constructor for Wall obstacle creation
 */
WallObstacle::WallObstacle()
{
}
