#include "drawing.hpp"
#include <SDL.h>
class Obstacles
{
protected:
    SDL_Rect srcRect, moverRect;
    int frame;
    //string type;
public:
    Obstacles();
    Obstacles (SDL_Rect srcRect);
    ~Obstacles();

    void draw();
};
