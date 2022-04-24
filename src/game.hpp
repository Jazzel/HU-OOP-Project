
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
/**
 * ? @brief Game
 * * the main game class, which defines the functionality of the game
 *
 * ? @attributes
 * * SCREEN WIDTH - int const, defining width of screen
 * * SCREEN HEIGHT - int const, defining height of screen
 * * gWindow- SDL_Window*, The window we'll be rendering to
 * * gTexture - SDL Texture * , Current displayed texture
 *
 * ? @functions
 * * BombObstacle()
 * *    - empty constructor which initializes the obstacle
 * * getObstacles(SDL_Rect)
 * *    - returns an pointing refernce to obstacle
 * *    - this function is override hence ploymorphism is used here for obstacle creation
 * * fly()
 * *    - it defines the path of the obstacle
 * *    - how the obstacle will draw away from center and move out of the screen
 */

class Game
{
    const int SCREEN_WIDTH = 1400;
    const int SCREEN_HEIGHT = 780;

    SDL_Window *gWindow = NULL;

    SDL_Texture *gTexture = NULL;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
};
