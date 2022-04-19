// ? header files
#include "ObjectCreater.hpp"

/**
 * ? @brief getObject()
 * * takes x and y pixels of screen and creates objects on the screen
 * * and random integer from 1 to 3
 * * objects here are pigeon, butterfly and bee
 * * store these objects in Unit * (inheritance)
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 * ? @return Unit *
 * * Unit pointing object of typeid (Bee, Butterfly or Pigeon)
 */
Unit *ObjectCreater::getObject(int random)
{

    Unit *object;
    switch (random)
    {
    case 1:
        object = new Pigeon();
        break;
    case 2:
        object = new Bee();
        break;
    case 3:
        object = new Butterfly();
        break;
    };

    return object;
}

/**
 * ? @brief Construct a new ObjectCreater:: ObjectCreater object
 * * default constructor
 *
 */
ObjectCreater::ObjectCreater()
{
}
