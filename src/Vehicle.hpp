#include <SDL.h>
#include <string>

#include "drawing.hpp"

class ScreenObject
{
public:
    SDL_Rect src, mover;
};

class Vehicle : public ScreenObject
{
private:
    int speed;
    int health;

public:
    Vehicle();
    ~Vehicle();

    void initVehicleMovement(std::string);
    void draw();
};
