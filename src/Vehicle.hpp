#pragma once

#include <SDL.h>
#include <string>

#include "Asset.hpp"
#include "drawing.hpp"

class Vehicle : public Asset
{
private:
    int speed;
    // int health;
public:
    Vehicle();
    ~Vehicle();

    void initVehicleMovement(std::string);
    void draw();
};
