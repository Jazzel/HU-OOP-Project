#include "Score.hpp"
#include "Asset.hpp"
#include "drawing.hpp"

Score::Score(/* args */)
{
    score = 0;
}

Score::~Score()
{
}

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

int Score::getScore()
{
    score++;
    return score;
}