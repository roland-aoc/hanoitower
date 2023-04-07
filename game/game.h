#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"
#include "util.h"

using std::string;

class Game
{
    Board board;
    milliseconds startTimeMillis;
    Utilizable* util;
    int maxMinutesPlayTime;
    

public:
    void setUp(int);
    Game(int, Utilizable*);
    Game(int);
    ~Game();
    int playWithScore(string, unsigned int);
    bool timeIsUp();
};

#endif