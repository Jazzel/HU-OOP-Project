#include "SquareObstacle.hpp"

vector<Obstacles *> SquareObstacle::initObstacles()
{
    SquareObstacle *asset = new SquareObstacle();
    asset->src = {55, 63, 292, 291};
    asset->mover = {695, 400, 20, 20};

    SquareObstacle *asset1 = new SquareObstacle();
    asset1->src = {55, 63, 292, 291};
    asset1->mover = {715, 430, 20, 20};

    SquareObstacle *asset2 = new SquareObstacle();
    asset2->src = {55, 63, 292, 291};
    asset2->mover = {675, 430, 20, 20};

    obstacles.push_back(asset);
    obstacles.push_back(asset1);
    obstacles.push_back(asset2);

    // cout << obstacles.size() << "Square triggered !!" << endl;

    return obstacles;
}
