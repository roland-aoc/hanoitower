#ifndef BOARD_H
#define BOARD_H

#include "spdlog/spdlog.h"

#include "rods.h"

#include <vector>
#include <string>
#include <stack>
#include <memory>

using std::string;
using std::vector;
using std::swap;
using std::for_each;
using std::move;
using std::make_unique;

template<typename T> using up = std::unique_ptr<T>;

class Board
{
    const up<rods_t> rods; 
    string status;
    bool smallest;

public:
    Board(); 
    ~Board() = default;
    void move(const int, const int) const;
    rods_t& getRods() const;
};


#endif