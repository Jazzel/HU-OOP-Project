#include "BombObstacle.hpp"

Obstacles *BombObstacle::getObstacles()
{
    BombObstacle *asset = new BombObstacle();
    asset->src = {1048, 59, 312, 369};

    // TODO : random pos

    asset->mover = {695, 400, 20, 20};

    // cout << obstacles.size() << "Square triggered !!" << endl;

    return asset;
}

BombObstacle::BombObstacle()
{
}
