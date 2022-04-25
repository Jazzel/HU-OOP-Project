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
 * * parent class to hold every functionality and objects
 * * that will be displayed and applied in the project
 *
 * ? @attributes
 * * private:
 * *  - gameObjects, screenObjects & scoreObjects
 * *      - vector of type pointers of Asset class,
 * *      - stores src & mover of objects to display on screen
 *
 * *  - obstacleObjects
 * *      - vector of type pointers of Obstacle class,
 * *      - stores obstacles of different type.
 *
 * *  - gameState
 * *      - holds values of enum class GameState - makes switch/if easier.
 *
 * *  - level
 * *      - holds values of enum class Level - makes switch/if easier.
 *
 * *  - vehicle
 * *      - a pointing reference to Vehicle class to enable vehicle implmentation.
 *
 * *  - score
 * *      - a pointing reference to Score class to enable score implmentation.
 *
 * *  - gameHealth
 * *      - a pointing reference to Health class to enable health implmentation.
 *
 * *  - theta
 * *      - type: double - to rotate obstacles.
 *
 * *  - backTheta
 * *      - type: double - to rotate background.
 *
 * *  - toggle, collide
 * *      - type: bool - enables class to store more obstacles in vector obstacleObjects.
 * *      - type: bool - enables class to check for collision.
 *
 * *  - counter, obstacleCounter
 * *      - type: int - counter for checking collision after every assigned value.
 * *      - type: int - counter for creating obstacle after every assigned value.
 * *
 *
 * ? @functions
 * * drawObjects():
 * *    - Reads the vectors gameObjects, screenObjects, scoreObjects & obstacleObjects
 * *    - calls their draw functions respectively.
 * *    - calls vehicle, score and health draw functions.
 * *    - deletes obstacles if they cross the limits.
 *
 * * onClickHandler(int, int):
 * *    - switches over the gameState variable for every Gamestate
 * *    - and checks if the pixels of any button or container matches with the mouse cords.
 * *    - Updates level and game state according to mouse click and previous gameState.
 *
 * * generateRandomInteger(int, int):
 * *    - Generates random int with a range.
 * *    - Takes 2 parameters(int) min and max to define the range.
 *
 * * init():
 * *    - initializes gameState to IDLE
 * *    - executes showScreens() function to show the splash screen.
 *
 * * createObstacles():
 * *    - generates random integers with generateRandomInteger(min, max)
 * *    - and creates obstacles of 4 types by completing the Obstacles class
 * *    - with it's child classes
 * *    - and finally pushes it to obstacleObjects vector.
 *
 * * makeMove(string):
 * *    - get RIGHT and LEFT as parameter form game.cpp
 * *    - and moves/rotates the vehicle/background respectively/
 *
 * * detectCollision(int, int, int, int, Obstacles *) - Function overloading !:
 * *    - gets the co-ordinates as integers of obstacles and checks
 * *    - if the vehicle co-ordinates matches with them
 * *    - gets obstacles and calls updateHealth(obstacle) from Health class
 * *    - to update health or finally overs the game.
 *
 * * detectCollision(float, float, float, float, Obstacles *) - Function overloading !:
 * *    - Rotating object takes SDLF_rect which contains float as variables so this
 * *    - gets the co-ordinates as floats of obstacles and checks
 * *    - if the vehicle co-ordinates matches with them
 * *    - gets obstacles and calls updateHealth(obstacle) from Health class
 * *    - to update health or finally overs the game.
 *
 * * showScore(int):
 * *    - gets the score as interger and seperates all the numbers from it
 * *    - gets the asstes of those numbers with checkNumber(number)
 * *    - and pusshes all the assets of these numbers to scoreObjects vector.
 *
 * * showScreens():
 * *    - switches over the gameState variable and defines the working
 * *    - for every case.
 * *    - fills the vectors gameObjects, screenObjects, scoreObjects & obstacleObjects
 * *    - accoring to the need and requirement of gameState and level State
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

    double backTheta = 0;
    double theta = 0;
    bool toggle = 1;
    bool collide = 0;
    int counter = 5;
    int obstacleCounter = 10;
    bool rotationSwitch = 1;

public:
    void init();
    void drawObjects();
    void createObstacles();
    int generateRandomInteger(int, int);
    void makeMove(string);
    void onClickHandler(int, int);
    void detectCollision(Obstacles *, int);
    void detectCollision(float, float, float, float, Obstacles *, int);
    void showScore(int);
    void showScreens();

    Bhuruz();
    ~Bhuruz();
};
