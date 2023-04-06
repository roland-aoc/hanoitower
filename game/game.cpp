#include "game.h"

#include <stdexcept>

using std::invalid_argument;

Game::Game(/* args */)
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
    return score;
}

void Game::setUp(int difficulty) {
    board.startingPos(difficulty);
}
