#include <vector>
#include <iostream>

using namespace std;

class Score
{
private:
    int score = 0;

public:
    Score();
    ~Score();

    int getScore();
    void incrementScore();
    void draw();
};
