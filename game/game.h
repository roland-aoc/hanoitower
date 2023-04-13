#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"
#include "util.h"

class Game
{
    const up<Board> board;
    milliseconds startTimeMillis;
    const up<Utilizable> util;
    int maxMinutesPlayTime;
    vector<int> movesFrom;
    vector<int> movesTo;
    vector<int> movesDiskSize;
    void recordMove(int, int, int);

public:
    Game(up<Board>&& board, int, up<Utilizable>&&);
    Game(int);
    ~Game() = default;
    void setUp(int);
    int playWithScore(const string, const unsigned int);
    bool timeIsUp();
};

#endif