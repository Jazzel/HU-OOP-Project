// ? imports
#include <iostream>
#include <iterator>

// ? header files
#include "Bhuruz.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? brief generateRandomInteger
 * * gives random number according to range given
 *
 * ? @param min
 * * int - the lowest number possible
 * ? @param max
 * * int - the highest number possible
 *
 * ! @return int
 * * random int
 */
int Bhuruz::generateRandomInteger(int min, int max)
{
    int range = max - min + 1;
    return rand() % range + min;
}

/**
 * ? @brief drawObjects()
 * * loops the list of objects
 * * and call very looped variable's (Unit *) draw function.
 *
 * * also when bee has passed the screen it deletes the pointing object
 * * and pops it from the list with the help of "deleteBee" helper from the class
 *
 */
void Bhuruz::drawObjects()
{

    // pig = new Pigeon(0, 0);
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->draw();
        /* code */
    }

    for (int i = 0; i < screenObjects.size(); i++)
    {
        // ass[i]->draw();
        SDL_RenderCopy(Drawing::gRenderer, Drawing::startAssets, &screenObjects[i]->src, &screenObjects[i]->mover);

        /* code */
    }

    // * used iterator to keep track of the objects in the loop
    // * also it helps to erase & delete the object pointer
    // list<Unit *>::iterator _iterator = objects.begin();
    // while (_iterator != objects.end())
    // {
    //     Unit *object = *_iterator;
    //     object->draw();
    //     Bee bee;
    //     if (typeid(*object).name() == typeid(bee).name())
    //     {
    //         if (((Bee *)(object))->deleteBee())
    //         {
    //             _iterator = objects.erase(_iterator);
    //             delete object;
    //             object = NULL;
    //         }
    //     }
    //     ++_iterator;
    // }
}

void Bhuruz::init()
{

    gameState = GameState::IDLE;
    Bhuruz::showScreens();

    // Bhuruz::showStartScreen();
}

void Bhuruz::showScreens()
{
    while (screenObjects.size())
    {
        screenObjects.pop_back();
    }
    switch (gameState)
    {
    case GameState::IDLE:
    {
        Asset *gameIcon = new Asset();
        gameIcon->mover = {430, 70, 543, 208};
        gameIcon->src = {1571, 71, 543, 208};

        Asset *startButton = new Asset();
        startButton->mover = {430, 350, 513, 170};
        startButton->src = {1721, 606, 508, 177};

        Asset *creditsButton = new Asset();
        creditsButton->mover = {450, 500, 513, 170};
        creditsButton->src = {1585, 354, 508, 171};

        screenObjects.push_back(gameIcon);

        screenObjects.push_back(startButton);
        screenObjects.push_back(creditsButton);
        break;
    }
    case GameState::CREDITS:
    {
        Asset *gameIcon = new Asset();
        gameIcon->mover = {430, 70, 543, 208};
        gameIcon->src = {1571, 71, 543, 208};

        Asset *creditsContainer = new Asset();
        creditsContainer->mover = {250, 270, 944, 429};
        creditsContainer->src = {44, 49, 944, 429};

        Asset *goBackButton = new Asset();
        goBackButton->mover = {1000, 690, 200, 80};
        goBackButton->src = {1089, 361, 266, 98};

        screenObjects.push_back(gameIcon);
        screenObjects.push_back(creditsContainer);
        screenObjects.push_back(goBackButton);
        break;
    }

    case GameState::LEVEL_SELECT:
    {

        Asset *gameIcon = new Asset();
        gameIcon->mover = {430, 70, 543, 208};
        gameIcon->src = {1571, 71, 543, 208};

        Asset *easyContainer = new Asset();
        easyContainer->mover = {260, 310, 680, 120};
        easyContainer->src = {1169, 1058, 1034, 229};

        Asset *mediumContainer = new Asset();
        mediumContainer->mover = {300, 450, 680, 120};
        mediumContainer->src = {25, 878, 992, 220};

        Asset *hardContainer = new Asset();
        hardContainer->mover = {340, 590, 680, 120};
        hardContainer->src = {109, 581, 947, 218};

        Asset *goBackButton = new Asset();
        goBackButton->mover = {1000, 690, 200, 80};
        goBackButton->src = {1089, 361, 266, 98};

        screenObjects.push_back(gameIcon);
        screenObjects.push_back(goBackButton);
        screenObjects.push_back(easyContainer);
        screenObjects.push_back(mediumContainer);
        screenObjects.push_back(hardContainer);
        break;
    }

    case GameState::RUNNING:
    {

        // Todo: vehicle

        // Todo: level background

        // Todo: score | speed

        // Todo: gameStart

        // Todo: obstacles

        Bhuruz::startGame();

        break;
    }

    case GameState::GAME_OVER:
    {
        Asset *gameOverIcon = new Asset();
        gameOverIcon->mover = {330, 200, 743, 221};
        gameOverIcon->src = {1155, 769, 743, 221};

        Asset *score = new Asset();
        score->mover = {350, 400, 200, 100};
        score->src = {2367, 1327, 363, 154};

        Asset *goBackButton = new Asset();
        goBackButton->mover = {1000, 690, 200, 80};
        goBackButton->src = {1089, 361, 266, 98};

        // Todo: add numbers for score

        screenObjects.push_back(gameOverIcon);
        screenObjects.push_back(score);
        screenObjects.push_back(goBackButton);

        break;
    }

    default:
        break;
    }
}

void Bhuruz::startGame()
{
    // gameState = GameState::GAME_OVER;

    Obstacles *obstacles = new Obstacles();
    obstacles->initObstacles();

    vehicle = new Vehicle();
    vehicle->initVehicle();

    Bhuruz::showScreens();
}

void Bhuruz::onClickHandler(int x, int y)
{
    if (gameState == GameState::LEVEL_SELECT)
    {
        if (x > 260 && y > 310 && x < 940 && y < 430)
        {
            cout << "Easy clicked !" << endl;
            level = Level::EASY;
            gameState = GameState::RUNNING;
        }
        else if (x > 300 && y > 450 && x < 980 && y < 570)
        {
            cout << "Medium clicked !" << endl;
            level = Level::MEDIUM;
            gameState = GameState::RUNNING;
        }
        else if (x > 340 && y > 590 && x < 1020 && y < 710)
        {
            cout << "Hard clicked !" << endl;
            level = Level::HARD;
            gameState = GameState::RUNNING;
        }
        else if (x > 1000 && y > 690 && x < 1200 && y < 770)
        {
            cout << "Go back clicked !" << endl;
            gameState = GameState::IDLE;
        }
    }
    else
    {
        if (x > 430 && y > 350 && x < 943 && y < 520)
        {
            cout << "Start clicked !" << endl;
            gameState = GameState::LEVEL_SELECT;
        }
        else if (x > 450 && y > 500 && x < 963 && y < 670)
        {
            cout << "Credits clicked !" << endl;
            gameState = GameState::CREDITS;
        }
        else if (x > 1000 && y > 690 && x < 1200 && y < 770)
        {
            cout << "Go back clicked !" << endl;
            gameState = GameState::IDLE;
        }
    }
    Bhuruz::showScreens();
}

/**
 * ? @brief createObject()
 * * takes x and y pixels of screen and creates objects on the screen
 * * calls ObjectCreater::getObject function to get object pointer of Unit class
 * * which containes reference to Bee, Butterfly or Pigeon class
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */

void Bhuruz::createObject(int x, int y)
{

    Bhuruz::onClickHandler(x, y);

    // int randomInteger = generateRandomInteger(1, 1);
    // objects.push_back(ObjectCreater::getObject(x, y, randomInteger));

    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void Bhuruz::makeMove(string direction)
{

    std::cout
        << "Direction: " << direction << std::endl;
    if (direction == "RIGHT")
    {
        cout << " fly \n";
        for (int i = 0; i < objects.size(); i++)
        {
            ((Pigeon *)objects[i])->fly("right");
        }
    }
    if (direction == "LEFT")
    {
        cout << " fly \n";
        for (int i = 0; i < objects.size(); i++)
        {
            ((Pigeon *)objects[i])->fly("left");
        }
    }
}

/**
 * ? @brief Destroy the Bhuruz::Bhuruz object
 * * emptys the objects list
 * * and deletes the pointing objects of classes in it
 */
Bhuruz::~Bhuruz()
{

    for (Unit *object : objects)
    {
        delete object;
        object = NULL;
    }
    objects.clear();
}
