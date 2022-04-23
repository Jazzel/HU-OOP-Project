#pragma once
#include "Obstacles.hpp"
#include <vector>
#include <iostream>

using namespace std;

class BombObstacle : public Obstacles
{
private:
public:
    BombObstacle();
    Obstacles *getObstacles() override;
};