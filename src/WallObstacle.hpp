#pragma once
// ? header files
#include "Obstacles.hpp"
// ? imports
#include <vector>
#include <iostream>

using namespace std;
/**
 * ? @brief WallObstacle
 * * child class inherited from obstacle class
 * * will create and display wall obstacle and define its functionality
 *
 * ? @attributes
 *
 * ? @functions
 * * WallObstacle()
 * *    - empty constructor which initializes the obstacle
 * * getObstacles(SDL_Rect)
 * *    - returns an pointing refernce to obstacle
 * *    - this function is override hence ploymorphism is used here for obstacle creation
 * * fly()
 * *    - it defines the path of the obstacle
 * *    - how the obstacle will draw away from center and move out of the screen
 */
class WallObstacle : public Obstacles
{
private:
public:
    WallObstacle();
    Obstacles *getObstacles(SDL_Rect) override;

    void fly();
};