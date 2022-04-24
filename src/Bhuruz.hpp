#pragma once
// ? imports
#include <SDL.h>
#include <vector>
#include <list>
#include <SDL_image.h>

// ? header files
#include "GameState.hpp"
#include "Level.hpp"
#include "Asset.hpp"
#include "Score.hpp"
#include "Health.hpp"
#include "Vehicle.hpp"

using namespace std;

/**
 * ? @brief Bhuruz
 * * parent class to hold the objects that will be displayed on the screen
 *
 * ? @attributes
 * * private: list of Unit class
 * * that are of data type pointers of Unit (Pigeon, Butterfly & Bee) class.
 *
 * ? @functions
 * * drawObjects():
 * *    - Reads the list of objects (list of type Unit *)
 * *    - and calls the draw the function of the class in the list
 * *    - checks if the class is Bee with "typeid" and calls special function "deleteBee"
 * *    - if the functions returns true then the bee is removed from the list and pointer is deleted
 *
 * * createObject(int, int):
 * *    - Gets random integer with the help of 'generateRandomInteger()' helper
 * *    - swithes according to random int and calls ObjectCreater::getObject
 * *    - which return pointing object of Unit class (containing reference of Bee, Butterfly or Pigeon)
 * *    - and pushes it into the list
 * *    - Takes 2 parameters(int) which defines the x and y pixel of mouse click.
 *
 * * generateRandomInteger(int, int):
 * *    - Generates random int with a range.
 * *    - Takes 2 parameters(int) min and max to define the range.
 *
 */

class Bhuruz
{
private:
    vector<Asset *> gameObjects;
    vector<Asset *> screenObjects;
    vector<Obstacles *> obstacleObjects;
    vector<Asset *> scoreObjects;

    GameState gameState;
    Level level;

    Vehicle *vehicle;
    Score *score;
    Health *gameHealth;

    bool _levelScreen = 0;
    double theta = 0;

    bool toggle = 1;

    bool collide = 0;

    int counter = 1;

    int obstacleCounter = 10;

public:
    void drawObjects();
    void createObject(int, int);
    void createObstacles();
    int generateRandomInteger(int, int);
    void makeMove(string);
    void init();
    void onClickHandler(int, int);
    void startGame();
    void detectCollision(int, int, int, int, Obstacles *);
    void detectCollision(float, float, float, float, Obstacles *);
    // void detectCollision(int, int, int, int, Obstacles *);
    void showScore(int);

    // void showCreditsScreen();
    // void showStartScreen();
    // void showLevelScreen();

    void showScreens();

    Bhuruz();
    ~Bhuruz();
};
