// ? header files
#include "pigeon.hpp"
#include <iostream>

// ! *******************************************************
// !         CLASS DEFINITION IN THE HEADER FILE
// ! *******************************************************

/**
 * ? @brief fly()
 * * switches the srcRect with the help of frame variable
 * * moves the pigeon to the right with the help of moverRect.x
 * * resets the pigeon back to left when it touches the right corner.
 *
 */

// void Pigeon::moveLeft()
// {
//     // std::cout << "runn !" << moverRect.x << "\n";
//     moverRect.x += 20;
//     // std::cout << "runn !" << moverRect.x << "\n";
// }

void Pigeon::fly(std::string direction)
{
    std::cout << direction << " <---\n";
    const int speed = 100;
    switch (frame)
    {
    case 0:
        srcRect = {7, 88, 155, 103};
        frame = 1;
        break;
    case 1:
        srcRect = {0, 237, 153, 84};
        frame = 2;
        break;
    case 2:
        srcRect = {2, 361, 159, 124};
        frame = 0;
        break;
    default:
        frame = 0;
        break;
    }
    if (direction == "right")
    {
        // ! Squaare

        if (moverRect.y == 600 && moverRect.x <= 1000)
        {
            moverRect.x += speed;
        }
        else if (moverRect.x >= 1000 && moverRect.y >= 200)
        {
            moverRect.y -= speed;
        }
        else if (moverRect.y >= 100 && moverRect.x >= 320)
        {
            moverRect.x -= speed;
        }
        else
        {
            moverRect.y += speed;
        }

        // // ! Pentagon
        // if (moverRect.y >= 600 && moverRect.x <= 880)
        // {
        //     moverRect.x += speed;
        // }
        // // else if (moverRect.y == 390)
        // // {
        // //     moverRect.y += speed;
        // // }
        // else if (moverRect.x >= 880 && moverRect.x <= 1100 && moverRect.y >= 340 && moverRect.y <= 600)
        // {
        //     moverRect.y -= (speed + int(speed / 2));
        //     moverRect.x += int(speed / 2);
        // }
        // else if (moverRect.x <= 480 && moverRect.x >= 200 && moverRect.y <= 600)
        // {
        //     moverRect.y += (speed + int(speed / 4));
        //     moverRect.x += int(speed + 20);
        // }
    }
    else
    {
        // ! square
        if (moverRect.y == 600 && moverRect.x >= 320)
        {
            moverRect.x -= speed;
        }
        else if (moverRect.y == 100 && moverRect.x <= 1000)
        {
            moverRect.x += speed;
        }
        else if (moverRect.x >= 320 && moverRect.y <= 600)
        {
            moverRect.y += speed;
        }
        else
        {
            moverRect.y -= speed;
        }

        // // ! pentagon
        // if (moverRect.y >= 600 && moverRect.x >= 480)
        // {
        //     moverRect.x -= speed;
        // }
        // else if (moverRect.x <= 1100 && moverRect.x >= 880 && moverRect.y <= 600 && moverRect.y >= 300)
        // {
        //     moverRect.y += (speed + int(speed / 2));
        //     moverRect.x -= int(speed / 2);
        // }
        // else if (moverRect.x <= 480 && moverRect.x >= 260 && moverRect.y >= 350 && moverRect.y <= 600)
        // {
        //     moverRect.y -= (speed + int(speed + 30));
        //     moverRect.x -= int(speed + 30);
        // }
        // else if (moverRect.y >= 390 && moverRect.x >= 100)
        // {
        //     moverRect.y -= speed;
        //     moverRect.x -= speed;
        // }
        // else if (moverRect.x >= 300 && moverRect.x <= 480 && moverRect.y <= 600 && moverRect.y >= 300)
        // {
        //     moverRect.y -= speed;
        //     moverRect.x -= speed;
        // }

        // else if (moverRect.y == 100 && moverRect.x <= 1000)
        // {
        //     moverRect.x += speed;
        // }
    }
    std::cout << "running";
}

/**
 * ? @brief Construct a new Pigeon:: Pigeon object - calls Unit constructor
 * * default constructor
 *
 */
Pigeon::Pigeon() : Unit({7, 88, 155, 103})
{
}

/**
 * ? @brief Construct a new Pigeon:: Pigeon object - calls Unit constructor
 * * constructor with x any y co-ordinates
 *
 * ? @param x
 * * x co-ordinate of the screen where mouse is clicked
 *
 * ? @param y
 * * y co-ordinate of the screen where mouse is clicked
 *
 */
Pigeon::Pigeon(int x, int y) : Unit({7, 88, 500, 500}, 680, 600)
{
}
