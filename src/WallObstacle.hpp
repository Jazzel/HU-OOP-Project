#pragma once
#include "Obstacles.hpp"
#include <vector>
#include <iostream>

using namespace std;

class WallObstacle : public Obstacles
{
private:
public:
    WallObstacle();
    Obstacles *getObstacles() override;
};