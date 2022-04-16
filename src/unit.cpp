// ? header files
#include "unit.hpp"

/**
 * ? @brief draw()
 * * draws the Unit with SDL params, srcRect and moveRect co-ordinates
 * * calls the fly() function to enable the animations
 *
 */
void Unit::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
    // fly();
}

void Unit::moveLeft()
{
    // std::cout << "runn !" << moverRect.x << "\n";
    Unit::moverRect.x += 20;
    // std::cout << "runn !" << moverRect.x << "\n";
}

/**
 * ? @brief fly() - virtual - default definition
 * ! redefintion replaces in Bee, Butterfly & Pigeon classes
 * * switches the srcRect with the help of frame variable
 * * moves the Unit to the right with the help of moverRect.x
 * * resets the Unit back to left when it touches the right corner.
 *
 */
void Unit::fly()
{
    switch (frame)
    {
    case 0:
        srcRect = {63, 619, 151, 166};
        frame = 1;
        break;
    case 1:
        srcRect = {234, 630, 163, 162};
        frame = 2;
        break;
    case 2:
        srcRect = {409, 650, 171, 147};
        frame = 0;
        break;
    default:
        frame = 0;
        break;
    }
    Unit::moverRect.x += 20;
    if (moverRect.x >= 1000)
    {
        Unit::moverRect.x = -50;
    }
}

/**
 * ? @brief Construct a new Unit:: Unit object
 * * constructor without x any y co-ordinates
 *
 * ? @param _srcRect
 * * srcRect of Pigeon, Butterfly or Bee class
 *
 */
Unit::Unit(SDL_Rect _srcRect) : srcRect(_srcRect)
{
}

/**
 * ? @brief Construct a new Unit:: Unit object
 * * constructor with x, y co-ordinates & _srcRect
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 * ? @param _srcRect
 * * srcRect of Pigeon, Butterfly or Bee class
 */
Unit::Unit(SDL_Rect _srcRect, int x, int y) : srcRect(_srcRect), moverRect({x, y, 80, 80})
{
}
