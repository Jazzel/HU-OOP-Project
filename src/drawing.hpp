#include <SDL.h>
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
};