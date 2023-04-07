#ifndef BOARD_H
#define BOARD_H

#include <stack>

#include "disk.h"

using std::stack;

class Board
{
stack<Disk*> rod1; 
stack<Disk*> rod2; 
stack<Disk*> rod3;
int startStackSize;

public:
    Board(/* args */);
    ~Board();
    void startingPos(int);
    bool moveFromFirstRod(char);
    bool moveFromSecondRod(char);
    bool moveFromThirdRod(char);
    bool hasWon();
};


#endif