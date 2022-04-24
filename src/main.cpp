//? headerfiles
#include "game.hpp"
/**
 * ? @brief main
 * * the main game class, which defines the functionality of the game
 *
 * ? @param
 * * SCREEN WIDTH - int const, defining width of screen
 * * SCREEN HEIGHT - int const, defining height of screen
 *      -
 */
int main(int argc, char *argv[])
{
    Game game;
    srand(time(NULL));
    if (!game.init())
    {
        printf("Failed to initialize!\n");
        return 0;
    }
    // Load media
    if (!game.loadMedia())
    {
        printf("Failed to load media!\n");
        return 0;
    }

    game.run();
    game.close();

    return 0;
}
