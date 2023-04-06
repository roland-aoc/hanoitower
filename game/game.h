#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"

using std::string;

class Game
{
Board board;

public:
    Game(/* args */);
    ~Game();
    int playWithScore(string, unsigned int);
    void setUp(int);
};

#endif