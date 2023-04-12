#include "game.h"
#include "util.h"
#include "util.cpp"

#include <stdexcept>

using std::invalid_argument;

Game::Game(Board* board, int maxMinutesPlayTime, Utilizable* util) 
    : board(board),
    maxMinutesPlayTime(maxMinutesPlayTime),
    util(util)
{
}

Game::Game(int maxMinutesPlayTime)
    : board(new Board),
    maxMinutesPlayTime(maxMinutesPlayTime),
    util(new Util)
{
}

Game::~Game()
{
}

int Game::playWithScore(string name, unsigned int nDisks) {
    if (nDisks >10) {
        throw invalid_argument("Must be smaller than 10"); 
    }
    int nMoves = 0;

    setUp(nDisks);
    spdlog::get("logger")->info("Game started with Player: {}", name);
    
    int left = 0, mid = 1, right = 2;
    int totalMoves = (1 << nDisks) - 1;
    if (nDisks % 2 == 0) {
        swap(mid, right);
    }
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 0)
            board->move(mid, right);
        else if (i % 3 == 1)
            board->move(left, right);
        else
            board->move(left, mid);
        nMoves++;
    }

    if (timeIsUp()) {
        spdlog::get("logger")->info("Player {} won with score {}", name, nMoves);
    } else {
        spdlog::get("logger")->error("Player {} has lost", name);
    }
    return nMoves; //TODO RK change interface
}

void Game::setUp(int nDisks) {
    startTimeMillis = util->logTime();
    for (int i = nDisks; i > 0; i--) board->getRods()[0].push(i);
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
