#include <SDL.h>
#include <SDL_mixer.h>

#pragma once
class Drawing
{
public:
    // The window renderer
    static SDL_Renderer *gRenderer;
    // global reference to png image sheets
    static SDL_Texture *assets;
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