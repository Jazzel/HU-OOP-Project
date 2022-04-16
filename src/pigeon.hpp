// ? imports
#include "unit.hpp"
#include <string>
/**
 * ? @brief Pigeon
 * ! inherits Unit class
 * * handles the Butterfly object and it's functions

 * ? @attributes
 * * SDL_Rect struct type of srcRect & moverRect - inherits from Unit class
 * *     - SDL_Rect stores int values x, y, w & h
 * * frame int type - inherits from Unit class
 **      - used to switch srcRect to animate the movement of object
 *
 * ? @functions
 * * draw() - inherits from Unit class
 * *     - draws the object Pigeon with moverRect, srcRect and SDL parameters
 * *     - calls fly() to trigger animation
 *
 * * fly() - reinitializes - Polymorphism
 * *     - animates the object Pigeon
 * *     - moves the Pigeon to the right of the screen
 * *     - and if it touches the right corner, resets it to the left corner
 * *     - switches the 3 srcRects continuosly to make the Pigeon flying real
 *
 *
 * ? @constructors
 * * Default
 * * with parameters (int, int)
 * *     - takes 2 params x and y and assign it to x and y of moverRect
 * *     - which makes the Pigeon object appear where the mouse click triggered.
 * *     - calls Unit class object to initialize Pigeon object
 *
 */
class Pigeon : public Unit
{
private:
public:
    void fly(std::string direction);
    // void moveLeft();

    Pigeon();
    Pigeon(int, int);
};
