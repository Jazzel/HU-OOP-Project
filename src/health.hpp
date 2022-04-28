#pragma once
//? imports
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
//? header files
#include "Asset.hpp"
#include "SquareObstacle.hpp"
#include "WallObstacle.hpp"
#include "BombObstacle.hpp"
#include "drawing.hpp"
#include "HealthObstacle.hpp"


using namespace std;
/** *
 * ? brief Health
 * * class inherited from Asset class for SDL_Rect type attributes
 * * Calculates and displays the health of the player upon the collision
 * 
 * ? attributes 
 * * private:
 * *    - health 
 * *        - type: int - an integer representing the current health of the player
 * 
 * ? functions
 * * updateHealth(Obstacle* obstacle):
 * *    - takes Obstacle pointer type object as an argument
 * *    - compares the type of obstacle with the different type of obstacles defined in the game and updates the health integer accordingly
 * 
 * * displayHealth():
 * *    - compares the health integer with the different discrete levels of health defined in the game (25,50,75,100) and displays the corresponding health bar
 * 
 * * getHealth():
 * *    - an inline getter function which returns the health integer when called
 * 
 * * Health():
 * *    a constructor function for the Health class
 * 
 * * operator ++()
 * *    moving vehicle right
 * 
 * * operator --()
 * *    moving vehicle left
 * */
class Health : public Asset
{
private:
    int health = 100;

public:
    void updateHealth(Obstacles *obstacle);
    void displayHealth();
    inline int getHealth() { return health; }

    Health();
};