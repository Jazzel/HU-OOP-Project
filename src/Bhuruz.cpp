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

    SDL_FPoint *q;
    SDL_FPoint pt;

    q = &pt;
    SDL_FRect *p;
    SDL_FRect moverRect;

    SDL_Event e;

    SDL_RendererFlip a = SDL_FLIP_NONE;
    // // pig = new Pigeon(0, 0);
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
            if (typeid(*obstacleObjects[i]).name() == typeid(SquareObstacle).name())
            {
                ((SquareObstacle *)(obstacleObjects[i]))->fly();
            }
            else if (typeid(*obstacleObjects[i]).name() == typeid(BombObstacle).name())
            {
                ((BombObstacle *)(obstacleObjects[i]))->fly();
            }
            else if (typeid(*obstacleObjects[i]).name() == typeid(HealthObstacle).name())
            {
                ((HealthObstacle *)(obstacleObjects[i]))->fly();
            }
            else if (typeid(*obstacleObjects[i]).name() == typeid(WallObstacle).name())
            {
                ((WallObstacle *)(obstacleObjects[i]))->fly();
            }

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
            counter = 20;
            collide = false;
        }
    }
}

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
                int randomSquare = generateRandomInteger(1, 3);
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

void Bhuruz::init()
{

    gameState = GameState::IDLE;

    Bhuruz::showScreens();

    // Bhuruz::showStartScreen();
}

void Bhuruz::showScreens()
{
    gameObjects = {};
    screenObjects = {};
    obstacleObjects = {};
    scoreObjects = {};

    _levelScreen = 0;
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

        gameHealth = new Health();
        score = new Score();

        obstacleObjects = {};
        // ? vehicle
        vehicle = new Vehicle();

        // ? level background
        ScreenObject *levelBackground = new ScreenObject();

        levelBackground->src = {0, 0, 1800, 1800};
        levelBackground->mover = {0, 0, 1800, 1800};

        gameObjects.push_back(levelBackground);

        // Todo: score | speed

        break;
    }

    case GameState::GAME_OVER:
    {
        // int x = 70;
        // int _score = score->getScore();
        // cout << "-----------" << scoreObjects.size() << endl;
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

        break;
    }

    default:
        break;
    }
}

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
    // else if (vehicle->mover.x <= (x + w) && (vehicle->mover.x + vehicle->mover.w) >= x)
}

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
    // else if (vehicle->mover.x <= (x + w) && (vehicle->mover.x + vehicle->mover.w) >= x)
}

void Bhuruz::startGame()
{
    // gameState = GameState::GAME_OVER;

    // Obstacles *obstacles = new Obstacles();
    // obstacles->initObstacles();

    // ScreenObject *vehicle = new Vehicle();
    // gameObjects.push_back(vehicle);

    // Bhuruz::showScreens();
}

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

Bhuruz::Bhuruz()
{
    gameObjects = {};
    screenObjects = {};
    obstacleObjects = {};
    scoreObjects = {};

    _levelScreen = 0;
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
