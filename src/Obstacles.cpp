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

void Obstacles::fly()
{
}

bool Obstacles::deleteObjects()
{
    if (mover.h > 1500)
    {
        return true;
    }
    return false;
}