#include <SDL.h>
#include <vector>
#include <list>

// ? header files
#include "unit.hpp"
#include "pigeon.hpp"
#include "bee.hpp"
#include "butterfly.hpp"

using namespace std;

/**
 * ? @brief ObjectCreater
 * * parent class to create the objects that will be displayed on the screen
 *
 * ? @functions
 *
 * * *getObject(int, int, int): - type static (to call it in HUMania class)
 * *    - Gets random integer with the help of 'generateRandomInteger()' helper as input
 * *    - swithes according to random int and and creates Pigeon, Bee or Butterfly pointing object
 * *    - stores it in Unit * as the classes are inherited by Unit class
 * *    - and returns pointing object of Unit class (containing reference of Bee, Butterfly or Pigeon)
 * *    - Takes 3 parameters(int) which defines the x and y pixel of mouse click &
 * *    - random interger to generate either Pigeon or Bee or Butterfly
 *
 */
class ObjectCreater
{
private:
public:
    ObjectCreater();

    static Unit *getObject(int);
};
