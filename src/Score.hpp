//? imports
#include <vector>
#include <iostream>
/**
 * ? @brief Score
 * * child class inherited from Asset class
 * * will create and display vehicle and define its functionality
 *
 * ? @attributes
 *
 * * private:
 * *    score- int, the total score in numbers which is updated on each cycle
 * *
 *
 * ? @functions
 * * Score()
 * *    - empty constructor which initializes the vehicle
 * * ~Score()
 * *    - destructor
 * * draw()
 * *    - by using an int position each corresponding object is drawn on the screen
 * *    - vector of int type stores all digits present in score
 * *        - src of each digit is extracted using helper function
 * *        - each object is drawn on the game over screen
 * *getScore()
 * *    - increments and returns the updtaed score
 */
using namespace std;

class Score
{
private:
    int score = 0;

public:
    Score();
    ~Score();

    int getScore();
    // void incrementScore();
    void draw();
};
