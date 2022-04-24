// ? imports
#include <iostream>
#include <iterator>

// ? header files
#include "Bhuruz.hpp"

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? @brief generateRandomInteger
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
 * * iterating over the gameObjects array which consist of pointing reference to assets
 * * using switch cases level is selected and drawn on canvas
 * * the background of level is rotated when vehicle is moved
 *
 * * calling the function for creating object
 * * checking the game level using Level class and setting unique counter value for each level
 * * using a counter for creating object, once the counter reaches zero new obstacle is created
 *
 * * iterating over obstacles object which consist of pointing reference to obstacles
 * * for medium and easy level obstacles are created and drawn out from the cenetr of the screen
 * * if the level is hard then obstacles are rotated too
 * * function detect collision is called which takes the moverRect and obstacle type as arguement
 * * if the function is drawn out of the screen then it is deleted
 *
 * * the vehicle is drawn
 * * health is displayed on th screen
 * * score is calculated and displayed on the screen
 * * all assets in screen object are vector are drawn
 *
 */
void Bhuruz::drawObjects()
{

    SDL_FPoint *q;
    SDL_FPoint pt;

    q = &pt;
    SDL_FRect *p;
    SDL_FRect moverRect;

    SDL_Event e;

    SDL_RendererFlip a = SDL_FLIP_NONE;
    if (gameState == GameState::RUNNING)
    {
        // ? level
        for (int i = 0; i < gameObjects.size(); i++)
        {
            switch (level)
            {
            case Level::EASY:
            {
                pt.x = 900;
                pt.y = 900;
                moverRect = {-195, -480, 1800, 1800};
                p = &moverRect;
                SDL_RenderCopyExF(Drawing::gRenderer, Drawing::levelOne, NULL, p, theta, q, a);
                break;
            }

            case Level::MEDIUM:
            {
                pt.x = 900;
                pt.y = 900;
                moverRect = {-195, -480, 1800, 1800};
                p = &moverRect;

                SDL_RenderCopyExF(Drawing::gRenderer, Drawing::levelTwo, NULL, p, theta, q, a);
                break;
            }

            case Level::HARD:
            {
                pt.x = 805;
                pt.y = 805;
                moverRect = {0, -400, 1600, 1600};
                p = &moverRect;

                SDL_RenderCopyExF(Drawing::gRenderer, Drawing::levelThree, NULL, p, theta, q, a);
                break;
            }

            default:
                break;
            }
        }

        /// ? obstacles
        Bhuruz::createObstacles();

        if (!toggle)
        {
            obstacleCounter--;
            if (obstacleCounter <= 0)
            {
                if (level == Level::EASY)
                {
                    obstacleCounter = 15;
                }
                else if (level == Level::MEDIUM)
                {
                    obstacleCounter = 10;
                }
                else if (level == Level::HARD)
                {
                    obstacleCounter = 8;
                }
                toggle = true;
            }
        }

        for (int i = 0; i < obstacleObjects.size(); i++)
        {

            pt.x = 10;
            pt.y = 10;
            moverRect = {(float)obstacleObjects[i]->mover.x, (float)obstacleObjects[i]->mover.y, (float)obstacleObjects[i]->mover.w, (float)obstacleObjects[i]->mover.h};
            p = &moverRect;
            obstacleObjects[i]->fly();

            if (level == Level::HARD)
            {
                SDL_RenderCopyExF(Drawing::gRenderer, Drawing::gameAssets, &obstacleObjects[i]->src, p, theta, q, a);
                detectCollision(moverRect.x, moverRect.y, moverRect.w, moverRect.h, obstacleObjects[i]);
            }
            else
            {
                SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &obstacleObjects[i]->src, &obstacleObjects[i]->mover);
                detectCollision(obstacleObjects[i]->mover.x, obstacleObjects[i]->mover.y, obstacleObjects[i]->mover.w, obstacleObjects[i]->mover.h, obstacleObjects[i]);
            }
            if (obstacleObjects[i]->deleteObjects())
            {
                obstacleObjects.erase(obstacleObjects.begin() + i);
            }
        }

        // ? score
        for (int i = 0; i < scoreObjects.size(); i++)
        {
            SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &scoreObjects[i]->src, &scoreObjects[i]->mover);
        }
        // ? vehicle
        gameHealth->displayHealth();
        vehicle->draw();

        // ? score
        Bhuruz::showScore(score->getScore());
    }

    if (gameState == GameState::GAME_OVER)
    {
        score->draw();
    }

    for (int i = 0; i < screenObjects.size(); i++)
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::startAssets, &screenObjects[i]->src, &screenObjects[i]->mover);
        /* code */
    }

    if (collide)
    {
        counter--;
        if (counter <= 0)
        {
            counter = 5;
            collide = false;
        }
    }
}

/**
 * ? @brief createObstacles()
 * * a random number is selected with the help of generate Random integer function
 * * using switch statements and polymorphism obstacles are created
 *
 * * for case 1 square obstacles are created, again random integer function is called
 * * there are 4 patterns for square object's mover Rect
 * * the obstcles is then pushed in the obstacles object vector which contains pointing reference to obstacle
 *
 * * for case 2, wall obstacle is created and its mover Rect is defined
 * * it is pushed into the obstacle objects vector
 *
 * * a position integer is generated using random function
 * * then using position the path of bomb and health is decided
 *
 * * for case 3. a bomb obstacle is created and is pushed in obstacles object vector
 *
 * * for case 4, first a bomb obstacle is created if the health is maximum
 * * then on same path health obstacle is created of smaller size
 * * health obstacle is then pushed into obstacles object vector
 *
 * * toggle, a boolean variable is changed so that new obstacle can be created
 */
void Bhuruz::createObstacles()
{
    if (gameState == GameState::RUNNING)
    {
        int random = generateRandomInteger(1, 4);
        // int random = 2;
        int position = generateRandomInteger(650, 680);
        if (toggle)
        {
            Obstacles *obstacles;

            switch (random)
            {
            case 1:
            {
                int randomSquare = generateRandomInteger(1, 4);
                // int randomSquare = 4;

                switch (randomSquare)
                {
                case 1:
                {
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({700, 392, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({650, 500, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({750, 500, 20, 20}));
                    break;
                }
                case 2:
                {
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({700, 500, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({650, 392, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({750, 392, 20, 20}));
                    break;
                }
                case 3:
                {
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({750, 406, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({650, 460, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({650, 352, 20, 20}));
                    break;
                }
                case 4:
                {
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({750, 352, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({650, 406, 20, 20}));
                    obstacles = new SquareObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({750, 460, 20, 20}));
                    break;
                }

                default:
                    break;
                }

                break;
            }
            case 2:
            {
                obstacles = new WallObstacle();
                obstacleObjects.push_back(obstacles->getObstacles({600, 392, 20, 60}));
                break;
            }

            case 3:
            {
                obstacles = new BombObstacle();
                obstacleObjects.push_back(obstacles->getObstacles({position, 392, 20, 20}));

                break;
            }
            case 4:
            {
                if (gameHealth->getHealth() == 100)
                {
                    obstacles = new BombObstacle();
                    obstacleObjects.push_back(obstacles->getObstacles({position, 392, 20, 20}));
                    break;
                }
                obstacles = new HealthObstacle();
                obstacleObjects.push_back(obstacles->getObstacles({position, 392, 20, 20}));
                break;
            }

            default:
                break;
            }
            toggle = false;
        }
    }
}
/**
 * ? @brief checkNumber()
 * * a pointing reference to asset is created
 * * using the number given as arguement through switch statements the src of asset is defined
 * ? @param number
 * * - int- a number which has to be displayed
 * ! return Asset*
 * * a pointing reference of asset containing src Rect of number to be displayed
 *
 */
Asset *checkNumber(int number)
{
    Asset *asset = new Asset();

    switch (number)
    {
    case 0:
        asset->src = {3817, 57, 240, 386};
        break;
    case 1:
        asset->src = {3818, 507, 157, 386};
        break;

    case 2:
        asset->src = {3831, 957, 238, 386};
        break;

    case 3:
        asset->src = {3814, 1407, 239, 386};
        break;

    case 4:
        asset->src = {3809, 1857, 255, 386};
        break;

    case 5:
        asset->src = {4224, 57, 236, 386};
        break;

    case 6:
        asset->src = {4222, 507, 238, 386};
        break;

    case 7:
        asset->src = {4227, 957, 240, 386};
        break;

    case 8:
        asset->src = {4218, 1407, 241, 386};
        break;

    case 9:
        asset->src = {4221, 1857, 238, 386};
        break;

    default:
        break;
    }
    return asset;
}
/**
 * ? @brief showScore()
 * * each element from score Objects vector conatining pointing refernce of assets displaying score is removed
 * * using score given as arguemnet, 5 numbers are generated
 * * pointing refernce to asset is created
 * * and it checks the number extracted above using defined function and defines its src
 * * mover rect of each 5 scoring digits is defined
 * * all assets are added in score objects vector
 *
 * ? @param score
 * * int - a number which has to be displayed on screen
 */
void Bhuruz::showScore(int score)
{
    while (scoreObjects.size())
    {
        scoreObjects.pop_back();
    }
    // cout << "Score: " << score << endl;
    int unit = score % 10;
    int ten = (score / 10) % 10;
    int hundred = (score / 100) % 10;
    int thousand = (score / 1000) % 10;
    int tenThousand = (score / 10000);

    Asset *asset = checkNumber(unit);
    asset->mover = {1300, 10, 70, 110};
    scoreObjects.push_back(asset);

    Asset *asset1 = checkNumber(ten);
    asset1->mover = {1240, 10, 70, 110};
    scoreObjects.push_back(asset1);

    Asset *asset2 = checkNumber(hundred);
    asset2->mover = {1180, 10, 70, 110};
    scoreObjects.push_back(asset2);

    Asset *asset3 = checkNumber(thousand);
    asset3->mover = {1120, 10, 70, 110};
    scoreObjects.push_back(asset3);

    Asset *asset4 = checkNumber(tenThousand);
    asset4->mover = {1060, 10, 70, 110};
    scoreObjects.push_back(asset4);
}
/**
 * ? @brief init()
 * * the game state is declared IDLE using gameState class
 * * show screen function is called to display the screen
 */
void Bhuruz::init()
{

    gameState = GameState::IDLE;

    Bhuruz::showScreens();

    // Bhuruz::showStartScreen();
}
/**
 * ? @brief showScreens()
 * * All vectors having pointing reference are initialized
 * * checking game state using switch statement
 * * if game state is IDLE, create object that are start button, credits button and game Icon
 * * and are added to screen objects vector so that they can be diaplyed
 *
 * * if game state is CREDITS, the credit screen is displayed as pointing refernces are created and added to screen objects vector
 * * game icon, credits and go back button are created and displayed
 *
 * * if game state is LEVEL_SELECT, the level selection screen is displayed
 * * as pointing refernces are created and added to screen objects vector
 * * game icon, back button and three levels conatiner are created
 *
 * * check if game state is RUNNING, dynamic score, vehicle, assets and background assets pointer is created
 * *  src and mover of level background is defined and are pushed into gameObjects vector
 *
 * * if game state is GAME OVER, then score, game over title and ho back button are created
 * * they are displayed on the screen by adding them to the screen object vector
 * * all previous music (bg music) is stopped
 * * specific sound effect is played
 */
void Bhuruz::showScreens()
{
    gameObjects = {};
    screenObjects = {};
    obstacleObjects = {};
    scoreObjects = {};

    theta = 0;

    toggle = 1;

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

        // ? health
        gameHealth = new Health();

        // ? score
        score = new Score();

        obstacleObjects = {};
        // ? vehicle
        vehicle = new Vehicle();

        // ? level background
        Asset *levelBackground = new Asset();

        levelBackground->src = {0, 0, 1800, 1800};
        levelBackground->mover = {0, 0, 1800, 1800};

        gameObjects.push_back(levelBackground);

        break;
    }

    case GameState::GAME_OVER:
    {

        Asset *gameOverIcon = new Asset();
        gameOverIcon->mover = {330, 200, 743, 221};
        gameOverIcon->src = {1155, 769, 743, 221};

        Asset *scoreText = new Asset();
        scoreText->mover = {450, 450, 200, 100};
        scoreText->src = {2513, 1026, 379, 139};

        Asset *goBackButton = new Asset();
        goBackButton->mover = {1000, 690, 200, 80};
        goBackButton->src = {1089, 361, 266, 98};

        screenObjects.push_back(gameOverIcon);
        screenObjects.push_back(scoreText);
        screenObjects.push_back(goBackButton);
        Mix_PauseMusic();

        Mix_PlayChannel(-1, Drawing::gGameOver, 0);

        break;
    }

    default:
        break;
    }
}
/**
 * ? @brief detectCollision()
 * * using vehicles's mover rect and integers arguements given checking whether ther is a collison or not
 * * in case of collision;s gameHealth class function update health is called and collide boolean variable is updated
 * * if health of vehicle is less than 0, update game state to game over and call show screen function
 *
 * ? @param x
 * * int - x co-ordinate of the object ( top right )
 *
 * ? @param y
 * * int - y co-ordinate of the object ( top right )
 *
 * ? @param h
 * * int - height of the object
 *
 * ? @param w
 * * int - width of the object
 *
 * ? @param obstacles*
 * * *obstacles- a pointing refernce to the obstacles for which collision is being checked
 */
void Bhuruz::detectCollision(int x, int y, int w, int h, Obstacles *obstacle)
{
    if (vehicle->mover.x <= (x + w) && (vehicle->mover.x + vehicle->mover.w) >= x && vehicle->mover.y <= (y + h) && (vehicle->mover.y + vehicle->mover.h) >= y && !collide)
    {
        cout << "Crashed !!" << endl;
        gameHealth->updateHealth(obstacle);
        if (gameHealth->getHealth() <= 0)
        {
            cout << "Game Over !!" << endl;
            gameState = GameState::GAME_OVER;
            Bhuruz::showScreens();
        }
        collide = true;
    }
}
/**
 * ? @brief detectCollision() function overloading
 * * using vehicles's mover rect and integers arguements given checking whether ther is a collison or not
 * * in case of collision;s gameHealth class function update health is called and collide boolean variable is updated
 * * if health of vehicle is less than 0, update game state to game over and call show screen function
 *
 * ? @param x
 * * float - x co-ordinate of the object ( top right )
 *
 * ? @param y
 * * float  - y co-ordinate of the object ( top right )
 *
 * ? @param h
 * * float  - height of the object
 *
 * ? @param w
 * * float  - width of the object
 *
 * ? @param obstacles*
 * * *obstacles- a pointing refernce to the obstacles for which collision is being checked
 */
void Bhuruz::detectCollision(float x, float y, float w, float h, Obstacles *obstacle)
{
    if (vehicle->mover.x <= (x + w) && (vehicle->mover.x + vehicle->mover.w) >= x && vehicle->mover.y <= (y + h) && (vehicle->mover.y + vehicle->mover.h) >= y && !collide)
    {
        cout << "Crashed !!" << endl;
        gameHealth->updateHealth(obstacle);
        if (gameHealth->getHealth() <= 0)
        {
            cout << "Game Over !!" << endl;
            gameState = GameState::GAME_OVER;
            Bhuruz::showScreens();
        }
        collide = true;
    }
}

/**
 * ? @brief onClickHandler()
 * * takes x and y pixels of screen and checks the game State
 * * if the Game State is level select, then the coordinates are used to check if the button has been clicked or not
 * * the level has been updated and obstacle counter is assigned uniquely, and game State changes to Running
 *
 * * all screen's except IDLE game state has back button, which updates the game state to IDLE state
 *
 * * IDLE state has 2 buttons, start and credits button which update game state to level select and credits respectively
 *
 * * all screens are diaplyed using show screens function
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */

void Bhuruz::onClickHandler(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;

    if (gameState == GameState::LEVEL_SELECT)
    {
        if (x > 260 && y > 310 && x < 940 && y < 430)
        {
            cout << "Easy clicked !" << endl;
            obstacleCounter = 15;
            level = Level::EASY;
            gameState = GameState::RUNNING;
        }
        else if (x > 300 && y > 450 && x < 980 && y < 570)
        {
            cout << "Medium clicked !" << endl;
            obstacleCounter = 10;
            level = Level::MEDIUM;
            gameState = GameState::RUNNING;
        }
        else if (x > 340 && y > 590 && x < 1020 && y < 710)
        {
            cout << "Hard clicked !" << endl;
            obstacleCounter = 8;
            level = Level::HARD;
            gameState = GameState::RUNNING;
        }
        else if (x > 1000 && y > 690 && x < 1200 && y < 770)
        {
            cout << "Go back clicked !" << endl;
            gameState = GameState::IDLE;
        }
        Bhuruz::showScreens();
    }
    else if (gameState == GameState::IDLE)
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
        Bhuruz::showScreens();
    }
    else if (gameState == GameState::CREDITS || gameState == GameState::LEVEL_SELECT || gameState == GameState::GAME_OVER)
    {
        if (x > 1000 && y > 690 && x < 1200 && y < 770)
        {
            cout << "Go back clicked !" << endl;
            gameState = GameState::IDLE;
        }
        Bhuruz::showScreens();
    }
}
/**
 * ? @brief makeMove()
 * * takes a string arguement and checks whther game state is running or not using gameState class
 * * vehicle's function for movement is called
 * * using the string direction theta is incremented or decremented
 * * theta is used to rotate the background canvas diaplying the level
 */
void Bhuruz::makeMove(string direction)
{
    if (gameState == GameState::RUNNING)
    {
        vehicle->initVehicleMovement(direction);
        if (direction == "RIGHT")
        {
            theta += 10;
        }
        else if (direction == "LEFT")
        {
            theta -= 10;
        }
    }
}
/**
 * ? @brief Bhuruz()
 * * an empty constructor, which initializes all vector
 * * sets boolean variable toggle to true and theta to zero
 */
Bhuruz::Bhuruz()
{
    gameObjects = {};
    screenObjects = {};
    obstacleObjects = {};
    scoreObjects = {};

    theta = 0;

    toggle = 1;
}

/**
 * ? @brief Destroy the Bhuruz::Bhuruz object
 * * emptys the objects list
 * * and deletes the pointing objects of classes in it
 */
Bhuruz::~Bhuruz()
{

    // for (Unit *object : objects)
    // {
    //     delete object;
    //     object = NULL;
    // }
    // objects.clear();
}
