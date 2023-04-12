#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"
#include "util.h"

using std::string;
using std::vector;
using std::swap;

class Game
{
    Board* board;
    milliseconds startTimeMillis;
    Utilizable* util;
    int maxMinutesPlayTime;
    vector<int> movesFrom;
    vector<int> movesTo;
    vector<int> movesDiskSize;
    void recordMove(int, int, int);

public:
    void setUp(int);
    Game(Board* board, int, Utilizable*);
    Game(int);
    ~Game();
    int playWithScore(string, unsigned int);
    bool timeIsUp();
};

#endif