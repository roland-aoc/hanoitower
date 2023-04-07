#include "game.h"
#include "util.h"
#include "util.cpp"

#include <stdexcept>

using std::invalid_argument;

Game::Game(int maxMinutesPlayTime, Utilizable* util) 
    : maxMinutesPlayTime(maxMinutesPlayTime),
    util(util)
{
}

Game::Game(int maxMinutesPlayTime) 
    : maxMinutesPlayTime(maxMinutesPlayTime),
    util(new Util)
{
}

Game::~Game()
{
}

int Game::playWithScore(string name, unsigned int difficulty) {
    if (difficulty >10) {
        throw invalid_argument("Must be smaller than 10"); 
    }
    int score = 0;

    setUp(difficulty);
    spdlog::get("logger")->info("Game started with Player: {}", name);

    while (!board.hasWon() && !timeIsUp()) {
        if (!board.moveFromFirstRod('2')) {
            score--;
            break;
        }
        if (!board.moveFromFirstRod('3')) {
            score--;
            break;
        }
        if (!board.moveFromSecondRod('3')) {
            score--;
            break;
        }
        if (!board.moveFromSecondRod('1')) {
            score--;
            break;
        }
    }
    if (timeIsUp()) {
        spdlog::get("logger")->info("Player {} won with score {}", name, score);
    } else {
        spdlog::get("logger")->error("Player {} has lost", name);
    }
    return 0; //TODO RK change interface
}

void Game::setUp(int difficulty) {
    startTimeMillis = util->logTime();
    board.startingPos(difficulty);
}

bool Game::timeIsUp() {
    //elapsed time no greater than maxMinutesPlayTime in ms
    return (duration_cast<milliseconds>(util->logTime() - startTimeMillis).count() < maxMinutesPlayTime * 60 * 10000); 
}
