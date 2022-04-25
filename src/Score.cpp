//? header files
#include "Score.hpp"
#include "Asset.hpp"
#include "drawing.hpp"
/**
 * ? @brief Score()
 * * empty constructor, ehich initializes score to zero
 */
Score::Score()
{
    score = 0;
}
/**
 * ? @brief ~Score()
 * * destructor
 */
Score::~Score()
{
}
/**
 * ? @brief getSRCNumber()
 * * it takes a number as arguements
 * * from 0 to 9, each switch statements represent a number
 * * if the number is found, its src is returned
 *
 * ? @param
 *
 * * int - number which has to be displayed
 *
 * ! return
 * * SDL-Rect, src of the score digit which has to be displayed
 */
SDL_Rect getSRCNumber(int number)
{
    SDL_Rect src;

    switch (number)
    {
    case 0:
        src = {3817, 57, 240, 386};
        break;
    case 1:
        src = {3818, 507, 157, 386};
        break;

    case 2:
        src = {3831, 957, 238, 386};
        break;

    case 3:
        src = {3814, 1407, 239, 386};
        break;

    case 4:
        src = {3809, 1857, 255, 386};
        break;

    case 5:
        src = {4224, 57, 236, 386};
        break;

    case 6:
        src = {4222, 507, 238, 386};
        break;

    case 7:
        src = {4227, 957, 240, 386};
        break;

    case 8:
        src = {4218, 1407, 241, 386};
        break;

    case 9:
        src = {4221, 1857, 238, 386};
        break;

    default:
        break;
    }
    return src;
}
/**
 * ? @brief draw()
 * * this function is used to display score on the game over screen
 * * a vector conatining integers named scored is created
 * * position an integer, by default is equal to 850.
 * *    -it is used to display number on appropriate position on screen
 * * each digit from score is extracted, pushed to vector, its src is extracted and its drawn on the screen
 * * pos is decremented by 50 to display corresponding digit
 *
 */
void Score::draw()
{
    int pos = 850;

    vector<int> scoreNumbers = {};
    int unit = score % 10;
    int ten = (score / 10) % 10;
    int hundred = (score / 100) % 10;
    int thousand = (score / 1000) % 10;
    int tenThousand = (score / 10000);

    scoreNumbers.push_back(unit);
    scoreNumbers.push_back(ten);
    scoreNumbers.push_back(hundred);
    scoreNumbers.push_back(thousand);
    scoreNumbers.push_back(tenThousand);

    for (int i = 0; i < scoreNumbers.size(); i++)
    {
        Asset *number = new Asset();
        number->src = getSRCNumber(scoreNumbers[i]);
        number->mover = {pos, 445, 70, 110};

        pos -= 50;
        SDL_RenderCopy(Drawing::gRenderer, Drawing::gameAssets, &number->src, &number->mover);
    }
}

/**
 * ? @brief  operator++
 * * overloaded ++ (increment) operator to update score automatically.
 *
 */
void Score::operator++()
{
    ++score;
}

/**
 * ? @brief getScore()
 * * score is incremented in this function and returs the updated score
 *
 * ! return
 * * int - score is returned
 */
int Score::getScore()
{
    return score;
}