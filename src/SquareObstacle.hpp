#pragma once
// ? header files
#include "Obstacles.hpp"
// ? imports
#include <vector>
#include <iostream>

using namespace std;
/**
 * ? @brief SquareObstacle
 * * child class inherited from obstacle class
 * * will create and display wall obstacle and define its functionality
 *
 * ? @attributes
 *
 * * public:
 * *    pos- int, which has default value 1. used for rotation
 *
 * ? @functions
 * * SquareObstacle()
 * *    - empty constructor which initializes the obstacle
 * * getObstacles(SDL_Rect)
 * *    - returns an pointing refernce to obstacle
 * *    - this function is override hence ploymorphism is used here for obstacle creation
 * * fly()
 * *    - it defines the path of the obstacle
 * *    - how the obstacle will draw away from center and move out of the screen
 */

class SquareObstacle : public Obstacles
{
private:
public:
    int pos = 1;

    SquareObstacle();

    void fly();
    Obstacles *getObstacles(SDL_Rect) override;
};
