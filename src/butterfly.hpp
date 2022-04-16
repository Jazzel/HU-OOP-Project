// ? imports
#include "unit.hpp"

/**
 * ? @brief Butterfly
 * ! inherits Unit class
 * * handles the Butterfly object and it's functions
 *
 *
 * ? @attributes
 * * SDL_Rect struct type of srcRect & moverRect - inherits from Unit class
 * *     - SDL_Rect stores int values x, y, w & h
 * * frame int type - inherits from Unit class
 * *      - used to switch srcRect to animate the movement of object
 * * down bool type
 * *      - default value true
 * *      - moves butterfly downward right
 * *      - after touching the bottom screen "down" becomes false
 * *      - which enables the upward right movement
 *
 * ? @functions
 * * draw() - inherits from Unit class
 * *     - draws the object Butterfly with moverRect, srcRect and SDL parameters
 * *     - calls fly() to trigger animation
 *
 * * fly() - reinitializes - Polymorphism
 * *     - animates the object Butterfly
 * *     - moves the Butterfly to the right of the screen
 * *     - and if it touches the right corner, resets it to the left corner
 * *     - switches the 3 srcRects continuosly to make the Butterfly flying real
 * *     - gets random number using "generateRandomInt()" helper
 * *     - get boolean value using "hover()" helper
 * *     - if the random number is 1 makes the hold (attribute) = 10
 *
 * ? @constructors
 * * Default
 * * with parameters (int, int)
 * *     - takes 2 params x and y and assign it to x and y of moverRect
 * *     - which makes the Butterfly object appear where the mouse click triggered.
 * *     - calls Unit class object to initialize Butterfly object
 *
 *
 */
class Butterfly : public Unit
{
private:
    bool down = true;

public:
    void fly();

    Butterfly();
    Butterfly(int, int);
};
