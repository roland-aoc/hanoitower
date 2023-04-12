#ifndef BOARD_H
#define BOARD_H

#include "spdlog/spdlog.h"

#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Board
{
    vector<stack<int>> rods; 
    string status;
    bool smallest;

public:
    Board(/* args */);
    ~Board();
    void move(int, int);
    vector<stack<int>>& getRods();
};


#endif