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

// rod1 4321
// rod2
// rod3

int Game::playWithScore(string name, unsigned int nDisks) {
    if (nDisks >10) {
        throw invalid_argument("Must be smaller than 10"); 
    }
    int nMoves = 0;

    setUp(nDisks);
    spdlog::get("logger")->info("Game started with Player: {}", name);
    
    int from, to, diskSize;
    
    // while (!board.hasWon()) { // && !timeIsUp() //TODO RK implement
    //     // spdlog::get("logger")->info("Current status\n{}", board.getStatus());
    //     calculateMove(from, to, diskSize);
    //     recordMove(from, to, diskSize);
    // }

    if (timeIsUp()) {
        spdlog::get("logger")->info("Player {} won with score {}", name, nMoves);
    } else {
        spdlog::get("logger")->error("Player {} has lost", name);
    }
    return nMoves; //TODO RK change interface
}

void Game::setUp(int nDisks) {
    startTimeMillis = util->logTime();
    board.startingPos(nDisks);
}

bool Game::timeIsUp() {
    //elapsed time no greater than maxMinutesPlayTime in ms
    return (duration_cast<milliseconds>(util->logTime() - startTimeMillis).count() < maxMinutesPlayTime * 60 * 10000); 
}

void Game::recordMove(int from, int to, int diskSize) {
    movesFrom.push_back(from);
    movesTo.push_back(to);
    movesDiskSize.push_back(diskSize);
}

void Game::calculateMove(int from, int to, int diskSize) {
    bool goodMove = true;
    if (goodMove) {
        from = util->randomTarget();
        to = util->randomTarget();
        // diskSize = get from vector
    }
}
