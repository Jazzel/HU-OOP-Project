#include "HealthObstacle.hpp"

Obstacles *HealthObstacle::getObstacles()
{
    HealthObstacle *asset = new HealthObstacle();
    asset->src = {1025, 635, 525, 323};

    // TODO : random pos

    asset->mover = {695, 400, 20, 20};

    // cout << obstacles.size() << "Square triggered !!" << endl;

    return asset;
}

HealthObstacle::HealthObstacle()
{
}
