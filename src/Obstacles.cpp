#include "Obstacles.hpp"

Obstacles::Obstacles(/* args */)
{
}

Obstacles::~Obstacles()
{
}

// vector<Obstacles *> Obstacles::initObstacles()
// {
//     cout << obstacles.size() << "Obstacles triggered !!" << endl;

//     return obstacles;
// }

void Obstacles::grow()
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (obstacles[i]->mover.x <= 200)
        {
            obstacles[i]->mover.x += 10;
            obstacles[i]->mover.y += 10;
        }
    }
}