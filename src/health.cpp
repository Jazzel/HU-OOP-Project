#pragma once
#include "health.hpp"
#include <iostream>


//#include "drawing.hpp"
using namespace std;

//Drawing::gameAssets = loadTexture("assets/game-assets.png");

void Health::updateHealth(Obstacles* obstacle){
    SquareObstacle square;
    WallObstacle wall;
    BombObstacle bomb;
    HealthObstacle healthbump;
    if (typeid(*obstacle).name() == typeid(square).name()){
        health -= 25;
    } else if (typeid(*obstacle).name() == typeid(wall).name()){
        health -= 50;
    } else if (typeid(*obstacle).name() == typeid(bomb).name()){
        health = 0;
    } else if (typeid(*obstacle).name() == typeid(healthbump).name()){
        health += 25;
    }
}

void Health::displayHealth(){
    if (health == 100){
        src = {88,1534,2045,176};
        mover = {30,30,1162,100};
    } elif (health == 75){
        src = {88,1290,1584,176};
        mover = {30,30,900,100};
    } elif (health == 50){
        src = {87,1056,1125,176};
        mover = {30,30,639,100};
    } elif (health == 25){
        src = {48,837,666,176};
        mover = {30,30,378,100};
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, src, mover);
}