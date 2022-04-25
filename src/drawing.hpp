//? imports
#include <SDL.h>
#include <SDL_mixer.h>
/**
 * ? @brief Drawing
 * * used to create the canvas, assets and for playing sounds
 *
 * ? @attributes
 *
 * * gRender - (static) used for window rendering, type SDL_Renderer *
 *
 * * startAssets - (static) a png which contains objects which are to be used in game, type SDL_Texture *
 * *        it conatins all 3 level containers
 * *        start, credits and back button
 * *        credits, contributor's name
 *
 * * levelOne - (static) the background for easy level, type SDL_Texture *
 * * levelTwo - (static) the background for medium level, type SDL_Texture *
 * * levelThree - (static) the background for difficult level, type SDL_Texture *
 *
 * * gCrash - sound effect for crashing, type (static) Mix_Chunk
 * * gHealth - sound effect for gaining health, type (static) Mix_Chunk
 * * gExplode - sound effect for explosion, type (static) Mix_Chunk
 * * gGameOver - sound effect for game over, type (static) Mix_Chunk
 */
#pragma once
class Drawing
{
public:
    // The window renderer
    static SDL_Renderer *gRenderer;
    // global reference to png image sheets
    static SDL_Texture *startAssets;
    static SDL_Texture *gameAssets;

    static SDL_Texture *levelOne;
    static SDL_Texture *levelTwo;
    static SDL_Texture *levelThree;

    // The sound effects that will be used
    static Mix_Chunk *gHealth;
    static Mix_Chunk *gCrash;
    static Mix_Chunk *gExplode;
    static Mix_Chunk *gGameOver;
};