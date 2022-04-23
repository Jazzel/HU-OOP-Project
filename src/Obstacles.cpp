#include "Obstacles.hpp"
#include "SquareObstacle.hpp"

Obstacles::Obstacles(/* args */)
{
}

Obstacles::Obstacles(SDL_Rect _srcRect) : src(_srcRect)
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
