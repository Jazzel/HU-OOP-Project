/**
 * ? @brief GameState- enum
 * * 3 levels are created each corresponding having increased difficulty level
 * * 1st the EASY level, which creates new obstacle after every 15 iterations
 * * 2nd the MEDIUM level, which creates new obstacle after every 10 iterations
 * * 3rd the HARd level which creates new obstacle after every 8 iterations and in this level the obstacles rotate also
 */

enum class Level
{
    EASY,
    MEDIUM,
    HARD
};