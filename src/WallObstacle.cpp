#include "WallObstacle.hpp"

Obstacles *WallObstacle::getObstacles()
{
    WallObstacle *asset = new WallObstacle();
    asset->src = {1642, 642, 1267, 444};

    // TODO : random pos

    asset->mover = {695, 400, 20, 20};

    // cout << obstacles.size() << "Square triggered !!" << endl;
    return asset;
}

WallObstacle::WallObstacle()
{
}
