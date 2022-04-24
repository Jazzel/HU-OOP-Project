#pragma once
#include <SDL.h>
/**
 * ? @brief Asset
 * * parent class to hold src and mover Rect of object
 * * all obstcales which are displayed on screen are inherited from this
 * ? @ attributes
 * * public:
 * *    - mover
 * *        contains the x and y coordinate of the screen 
 * *        along with height and width are used to display object
 * *    - src
 * *        contains the x and y coordinate of the object from assets resource 
 * *        along with height and width are used to define and extract the object
  */
class Asset
{
public:
    SDL_Rect mover, src;
};