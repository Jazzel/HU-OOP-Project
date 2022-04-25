#pragma once
//? header files
#include "drawing.hpp"
//? imports
#include <SDL.h>
#include <vector>
#include <iostream>

using namespace std;
/**
 * ? @brief Obstacles
 * * parent class from which other obstacle classes are inherited
 * * will create and display obstacle and define its functionality
 *
 * ? @attributes
 * * public:
 * *    - mover
 * *        contains the x and y coordinate of the screen
 * *        along with height and width are used to display object
 * *    - src
 * *        contains the x and y coordinate of the object from assets resource
 * *        along with height and width are used to define and extract the object
 *
 * ? @functions
 * * Obstacle()
 * *    - empty constructor which initializes the obstacle
 * * ~Obstacle()
 * *    - destructor
 * * deleteObjects()
 * *    - a function which returns a boolean variable which indicates if object is out of screen or not
 * * getObstacles(SDL_Rect)
 * *    - returns an pointing refernce to obstacle
 * *    - this function is pure virtual function which would be further used for polymorphism
 * * fly()
 * *    - it defines the path of the obstacle
 * *    - how the obstacle will draw away from center and move out of the screen
 * *    - this a virtual function which would be used further for polymorphism
 */
class Obstacles
{
public:
    SDL_Rect src, mover;

public:
    Obstacles();
    ~Obstacles();

    bool deleteObjects();
    virtual Obstacles *getObstacles(SDL_Rect) = 0;
    virtual void fly();
};
