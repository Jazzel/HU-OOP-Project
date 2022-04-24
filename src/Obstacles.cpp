#include "Obstacles.hpp"
#include "SquareObstacle.hpp"

Obstacles::Obstacles(/* args */)
{
}

Obstacles::~Obstacles()
{
}

void Obstacles::fly()
{
} // yes fly object

bool Obstacles::deleteObjects()
{
    if (mover.h > 1500)
    {
        return true;
    }
    return false;
}