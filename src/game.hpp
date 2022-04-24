//?imports
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
 * * init()
 * *    - initializes SDL, the image loader and SDL mixer
 * *    - this function creates the window and renderer and assigns default colour to it (white)
 * *    - checks whether there is no error in SDL initialization
 * * loadTexture(string)
 * *    - takes a string path for image and all loads that image into SDL surface
 * *    - returns a poiniting reference to new created surface
 * * run()
 * *    - it takes input from the user, either arrow keys or mouse and desired functionality is defined
 * *    - sdl delay is used to dealy our frame, new renderer is created and displayed
 * *    - background music is played continously using loop to create a pleasant experience for user
 * * loadMedia()
 * *    - loads images using SDL texture that are used either for assets or for background
 * *    - loads sound effects and background music using SDL mixer
 * * close ()
 * *    - using SDL's destroy and mixer free function all images and sound effects are destroyed
 * *    - destroying renderer and window, quitting all systems
 * *    - this function is called at the end of thr program
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
