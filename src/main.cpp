//? headerfiles
#include "game.hpp"
/**
 * ? @brief main
 * * the main game class, which defines the functionality of the game
 * * it creates a game object, calls its init function to check textures, audios, assets
 * * using game's function loads media
 * * calls game's run to play the game
 * * game's close command deletes all objects, screens by using Quit commands
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
