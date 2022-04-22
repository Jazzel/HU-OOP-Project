#include "Vehicle.hpp"
#include <iostream>

using namespace std;

void Vehicle::initVehicleMovement(string direction)
{
    // cout << "Direction: " << direction << endl;
    if (direction == "RIGHT")
    {
        if (mover.y == 600 && mover.x <= 950)
        {
            mover.x += speed;
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
        if (mover.y == 600 && mover.x >= 320)
        {
            mover.x -= speed;
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

void Vehicle::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &src, &mover);
}

Vehicle::Vehicle()
{
    src = {2722, 1334, 488, 252};
    mover = {620, 600, 110, 80};

    speed = 40;
}

Vehicle::~Vehicle()
{
}
