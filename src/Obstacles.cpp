//? header files
#include "Obstacles.hpp"
#include "SquareObstacle.hpp"
/**
 * ? @brief Obstacle()
 * * an empty constructor for square obstacle creation
 */
Obstacles::Obstacles()
{
}
/**
 * ? @brief ~Obstacle()
 * * a destructor which is responsible for deleting obstacle
 */
Obstacles::~Obstacles()
{
}
/**
 * ? @brief fly()
 * * a virtual function which is override by each child class that is type of obstacle
 * * it would define the path of the object
 */
void Obstacles::fly()
{
}
/**
 * ? @brief deleteObjects()
 * * checks if the mover's height is greater than the size of screen then boolean variable is true otherwise false
 * ! return
 * * a boolean variable which is true if the object is out of screen
 */
bool Obstacles::deleteObjects()
{
    if (mover.h > 1500)
    {
        return true;
    }
    return false;
}