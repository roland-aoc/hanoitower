#ifndef GAME_H
#define GAME_H

#include <string>

#include "board.h"

using std::string;

class Game
{
void setUp(int);
Board board;

public:
    Game(/* args */);
    ~Game();
    int playWithScore(string, unsigned int);
};

#endif