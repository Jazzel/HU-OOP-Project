/**
 * ? @brief GameState- enum
 * * five game states are created
 * * 1st the IDLE state appearing at the start of the game
 * * 2nd the level select, which allows the user to select the difficulty level of the game
 * * 3rd the game running state, in which the obstacles are randomly created and user can enjoy the game
 * * 4th the game over state, which appears when a person has lost and displays score
 * * 5th credits screen, which display the names of the contributors
 */
enum class GameState
{
    IDLE,
    LEVEL_SELECT,
    RUNNING,
    GAME_OVER,
    CREDITS,
};