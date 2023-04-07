#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

#include "disk.h"

using std::vector;
using std::string;

class Board
{
vector<Disk*> rod1; 
vector<Disk*> rod2; 
vector<Disk*> rod3;
int startSize;
string status;

public:
    Board(/* args */);
    ~Board();
    void startingPos(int);
    bool moveFromFirstRod(char);
    bool moveFromSecondRod(char);
    bool moveFromThirdRod(char);
    bool hasWon();
    string& getStatus();
};


#endif