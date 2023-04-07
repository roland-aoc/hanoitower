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

// if available moves, the most valuable move first: highest one to the right, but not 1 (it's often getting stuck)
// (don't revert the move again unless stuck which is same sequence of moves in pairs of 4,5,6,7,8 three times)
//    if stuck
//      clean stack on right
// if not, just try to to make a move

int Game::playWithScore(string name, unsigned int difficulty) {
    if (difficulty >10) {
        throw invalid_argument("Must be smaller than 10"); 
    }
    int score = 0;

    setUp(difficulty);
    spdlog::get("logger")->info("Game started with Player: {}", name);
    
    int from, to, diskSize;
    
    while (!board.hasWon()) { // && !timeIsUp() //TODO RK implement
        spdlog::get("logger")->info("Current status\n{}", board.getStatus());
        calculateMove(from, to, diskSize);
        recordMove(from, to, diskSize);
        if (1 == from) {
            board.moveFromFirstRod(to);
        }
        if (2 == from) {
            board.moveFromSecondRod(to);
        }
        if (3 == from) {
            board.moveFromThirdRod(to);
        }
        
        if (!board.moveFromFirstRod(util->randomTarget())) {
            score--;
            continue;
        }
        if (!board.moveFromSecondRod(util->randomTarget())) {
            score--;
            continue;
        }
        // if (!board.moveFromSecondRod('3')) {
        //     score--;
        //     continue;
        // }
        // if (!board.moveFromSecondRod('1')) {
        //     score--;
        //     continue;
        // }
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

void Game::recordMove(int from, int to, int diskSize) {
    movesFrom.push_back(from);
    movesTo.push_back(to);
    movesDiskSize.push_back(diskSize);
}

void Game::calculateMove(int& from, int& to, int& diskSize) {
    bool goodMove = true;
    if (goodMove) {
        from = util->randomTarget();
        to = util->randomTarget();
        // diskSize = get from vector
    }
}
