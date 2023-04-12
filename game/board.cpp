#include "board.h"

#include <algorithm>

using std::for_each;
using std::begin;
using std::end;

Board::Board(/* args */)
    : rods(3)
{
}

Board::~Board()
{
}

void Board::move(int from, int to) {
    if (rods[to].empty() || (!rods[from].empty() && rods[from].top() < rods[to].top()))
    {
        rods[to].push(rods[from].top());
        rods[from].pop();
    }
    else
        move(to, from);
}

vector<stack<int>>& Board::getRods() {
    return rods;
}