// ? imports
#include "unit.hpp"

/**
 * ? @brief Bee
 * ! inherits Unit class
 * * handles the Bee object and it's functions
 *
 * ? @attributes
 * * SDL_Rect struct type of srcRect & moverRect - inherits from Unit class
 * *     - SDL_Rect stores int values x, y, w & h
 * * frame int type - inherits from Unit class
 * *      - to switch srcRect to animate the movement of object
 * * hold int type
 * *      - to hold the bee for 10 frames
 * *      - -1 means the bee will not be held
 * *      - it becomes 10 if the probability is 1
 * *      - then decrement makes it back to 0 which lets the bee move again
 *
 * ? @functions
 * * draw() - inherits from Unit class
 * *     - draws the object Bee with moverRect, srcRect and SDL parameters
 * *     - calls fly() to trigger animation
 *
 * * fly() - reinitializes - Polymorphism
 * *     - animates the object Bee
 * *     - moves the Bee to the right of the screen
 * *     - and if it touches the right corner, resets it to the left corner
 * *     - switches the 3 srcRects continuosly to make the Bee flying real
 * *     - gets random number using "generateRandomInt()" helper
 * *     - get boolean value using "hover()" helper
 * *     - if the random number is 1 makes the hold (attribute) = 10
 *
 * * deleteBee()
 * *     - returns true if the bee has crossed the whole screen
 *
 * * hover()
 * *     - generates probabilty of 1 and assigns 10 to hold variable
 * *     - returns true if hold is not 0 or -1
 *
 * * generateRandomInt()
 * *    - Generates random int with a range.
 * *    - Takes 2 parameters(int) min and max to define the range.
 *
 * ? @constructors
 * * Default
 * * with parameters (int, int)
 * *     - takes 2 params x and y and assign it to x and y of moverRect
 * *     - which makes the Bee object appear where the mouse click triggered.
 * *     - calls Unit class object to initialize Bee object
 *
 */
class Bee : public Unit
{
private:
    int hold = -1;

public:
    bool deleteBee();
    bool hover();
    int generateRandomInt(int, int);
    void fly();

    Bee();
    Bee(int, int);
};
