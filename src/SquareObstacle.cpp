#include "SquareObstacle.hpp"

Obstacles *SquareObstacle::getObstacles()
{
    SquareObstacle *asset = new SquareObstacle();
    asset->src = {55, 63, 292, 291};
    asset->mover = {695, 400, 20, 20};

    return asset;
}

SquareObstacle::SquareObstacle()
{
}