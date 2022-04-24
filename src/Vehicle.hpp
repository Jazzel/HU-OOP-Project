#pragma once
//? imports
#include <SDL.h>
#include <string>
//? header files
#include "Asset.hpp"
#include "drawing.hpp"
/**
 * ? @brief Vehicle
 * * child class inherited from Asset class
 * * will create and display vehicle and define its functionality
 *
 * ? @attributes
 *
 * * private:
 * *    speed- int, it is used to increment or decrement mover's x coordiante
 * *    
 *
 * ? @functions
 * * Vehicle()
 * *    - empty constructor which initializes the vehicle
 * * ~Vehicle()
 * *    - destructor
 * * initVehicleMovement(string)
 * *    - checks the direction ehich is given as string
 * *    - if the vehicle's mover is within limit, increment or decrement mover's x depending on arguement
 * * draw()
 * *    - it draws the vehicle using SDL_Rendercopy
 */
class Vehicle : public Asset
{
private:
    int speed;
public:
    Vehicle();
    ~Vehicle();

    void initVehicleMovement(std::string);
    void draw();
};
