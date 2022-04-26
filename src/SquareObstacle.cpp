//? header files
#include "SquareObstacle.hpp"
/**
 * ? @brief getobstacle()
 * * dynamically creates a square obstacle using polymorphism
 * * defnes the assets's src and assigns mover which is given as parameter
 *
 * ? @param
 *
 * * SDL_RECT - mover, where the object has to be created
 *
 * ! return
 * * obstacles * - a pointing reference to obstacle which is created
 */
Obstacles *SquareObstacle::getObstacles(SDL_Rect mover)
{
    SquareObstacle *asset = new SquareObstacle();
    asset->src = {55, 63, 292, 291};
    asset->mover = mover;

    return asset;
}
/**
 * ? @brief fly()
 * * using the x and y coordinate the position of the square is checked
 * * hence by using the position, the path is defined in such a way that each path is unique
 * * the height and width of the wall is increased hence to create a 3d perspective
 */
void SquareObstacle::fly()
{
    if (mover.y <= 400 && mover.x == 700)
    {
        mover.y -= 10;
    }
    else if (mover.y >= 500 && mover.x == 700)
    {
        mover.y += 10;
    }
    else if (mover.x <= 650 && mover.y >= 500)
    {
        mover.x -= 10;
        mover.y += 10;
    }
    else if (mover.x >= 700 && mover.y >= 500)
    {
        mover.x += 10;
        mover.y += 10;
    }
    else if (mover.x <= 650 && mover.y <= 392)
    {
        mover.x -= 10;
        mover.y -= 10;
    }
    else if (mover.x >= 700 && mover.y <= 392)
    {
        mover.x += 10;
        mover.y -= 10;
    }
    else if (mover.x <= 650)
    {
        mover.x -= 10;
        mover.y += 10;
    }
    else if (mover.x >= 650)
    {
        mover.x += 10;
        mover.y += 10;
    }

    mover.h += 4;
    mover.w += 4;
}
/**
 * ? @brief SquareObstacle()
 * * an empty constructor for square obstacle creation
 */
SquareObstacle::SquareObstacle()
{
}