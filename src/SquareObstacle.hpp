#pragma once
#include "Obstacles.hpp"
#include <vector>
#include <iostream>

using namespace std;

class SquareObstacle : public Obstacles
{
private:
public:
    SquareObstacle();

    Obstacles *getObstacles() override;
};
