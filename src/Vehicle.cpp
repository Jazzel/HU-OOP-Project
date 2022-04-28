//? header files
#include "Vehicle.hpp"
//? imports
#include <iostream>

using namespace std;
/**
 * ? @brief operator ++()
 * * increment the mover's x by speed
 *
 */
void Vehicle::operator++ () {
    mover.x += speed; 
}
/**
 * ? @brief operator --()
 * * decrement the mover's x by speed
 *
 *
 */
void Vehicle::operator-- () {
    mover.x -= speed; 
}



/**
 * ? @brief initVehicleMovement()
 * * checks if the direction, a string type is right or left
 * * if the mover's coordinate are with in the range of movement
 *
 * ? @param
 *
 * * direction - string, telling where the vehicle has to move
 * !return 
 * * a boolean telling if the vehicle has to be moved or not
 *
 */
bool Vehicle::initVehicleMovement(string direction)
{
    // cout << "Direction: " << direction << endl;
    if (direction == "RIGHT")
    {
        if (mover.y == 600 && mover.x <= 930)
        {
            // mover.x += speed;
            return true;

        }
        // else if (mover.x >= 950 && mover.y >= 150)
        // {
        //     mover.y -= speed;
        // }
        // else if (mover.y >= 50 && mover.x >= 320)
        // {
        //     mover.x -= speed;
        // }
        // else
        // {
        //     mover.y += speed;
        // }
    }
    else if (direction == "LEFT")
    {
        if (mover.y == 600 && mover.x >= 380)
        {
           true;
        }
        // else if (mover.y == 100 && mover.x <= 950)
        // {
        //     mover.x += speed;
        // }
        // else if (mover.x >= 320 && mover.y <= 600)
        // {
        //     mover.y += speed;
        // }
        // else
        // {
        //     mover.y -= speed;
        // }
    }
}
/**
 * ? @brief draw()
 * * draws the vehicle by using SDL's command of RenderCopy which takes parameters:
 * *        - gRender, assets, src and mover of vehicle
 */
void Vehicle::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &src, &mover);
}
/**
 * ? @brief Vehicle()
 * * empty vehicle constructor
 * * defines the mover and src of the vehicle
 * * speed is set as by defualt 40
 */
Vehicle::Vehicle()
{
    src = {2722, 1334, 488, 252};
    mover = {620, 600, 110, 80};

    speed = 40;
}

/**
 * ? @brief ~Vehicle()
 * * destructor
 */


Vehicle::~Vehicle()
{
}
