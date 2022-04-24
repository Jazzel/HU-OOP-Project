#include "SquareObstacle.hpp"

Obstacles *SquareObstacle::getObstacles(SDL_Rect mover)
{
    SquareObstacle *asset = new SquareObstacle();
    asset->src = {55, 63, 292, 291};
    asset->mover = mover;

    return asset;
}

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

    mover.h += 5;
    mover.w += 5;
    // SquareObstacle obstacles = new SquareObstacle();
    // obstacles->mover = {700, 392, 20, 20};
    // obstacleObjects.push_back(obstacles->getObstacles());
    // SquareObstacle obstacles = new SquareObstacle();
    // obstacles = new SquareObstacle();
    // obstacles->mover = {650, 500, 20, 20};
    // obstacleObjects.push_back(obstacles->getObstacles());
    // SquareObstacle obstacles = new SquareObstacle();
    // obstacles->mover = {750, 500, 20, 20};
    // obstacleObjects.push_back(obstacles->getObstacles());
}

SquareObstacle::SquareObstacle()
{
}