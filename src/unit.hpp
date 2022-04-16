#pragma once
// ? imports
#include <SDL.h>
#include <string>

// ? header files
#include "drawing.hpp"

/**
 * ? @brief Unit
 * * handles the Unit object and it's functions
 * ! extends Bee, Buttefly and Unit class

 * ? @attributes
 * * SDL_Rect struct type of srcRect & moverRect
 * *     - SDL_Rect stores int values x, y, w & h
 * * frame int type
 **      - used to switch srcRect to animate the movement of object
 *
 * ? @functions
 * * draw()
 * *     - draws the object Unit with moverRect, srcRect and SDL parameters
 * *     - calls fly() to trigger animation
 *
 * * fly() - type virtual - Polymorphism applied !
 * *     - animates the object Unit
 * *     - moves the Unit to the right of the screen
 * *     - and if it touches the right corner, resets it to the left corner
 * *     - switches the 3 srcRects continuosly to make the Unit flying real
 *
 *
 * ? @constructors
 * * Default
 * * with parameters (int, int)
 * *     - takes 2 params x and y and assign it to x and y of moverRect
 * *     - which makes the Unit object appear where the mouse click triggered.
 *
 */
class Unit
{
protected:
public:
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    Unit(SDL_Rect _srcRect);
    Unit(SDL_Rect _srcRect, int x, int y);

    void draw();
    void moveLeft();
    virtual void fly();
};
