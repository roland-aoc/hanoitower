#include "board.h"

#include <algorithm>
#include <utility>

Board::Board()
    : rods(make_unique<rods_t>(3)) {
}

void Board::move(const int from, const int to) const {
    if (rods->at(to).empty() || (!rods->at(from).empty() && rods->at(from).top() < rods->at(to).top()))
    {
        rods->at(to).push(rods->at(from).top());
        rods->at(from).pop();
    }
    else
        move(to, from);
}

rods_t& Board::getRods() const {
    return *rods;
}