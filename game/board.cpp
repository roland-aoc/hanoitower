#include "board.h"

Board::Board(/* args */)
{
}

Board::~Board()
{
}

void Board::startingPos(int difficulty) {
    for (int i = 0; i < difficulty; i++) {
        rod1.push(new Disk(i));
    }
}

bool Board::moveFromFirstRod(char target) {
    if (rod1.empty()) {
        return false;
    }
    if ('1' == target) {
        return false;
    }
    if ('2' == target) {
        if (!rod2.empty()) {
            if (rod1.top()->getSize() > rod2.top()->getSize()) {
                return false;
            }
        }
        rod2.push(rod1.top());
        rod1.pop();
    }
    if ('3' == target) {
        if (!rod3.empty()) {
            if (rod1.top()->getSize() > rod3.top()->getSize()) {
                return false;
            }
        }
        rod3.push(rod1.top());
        rod1.pop();
    }
    return true;
}

bool Board::moveFromSecondRod(char target) {
    if (rod2.empty()) {
        return false;
    }
    if ('1' == target) {
        if (!rod1.empty()) {
            if (rod2.top()->getSize() > rod1.top()->getSize()) {
                return false;
            }
        }
        rod1.push(rod2.top());
        rod2.pop();
    }
    if ('2' == target) {
        return false;
    }
    if ('3' == target) {
        if (!rod3.empty()) {
            if (rod2.top()->getSize() > rod3.top()->getSize()) {
                return false;
            }
        }
        rod3.push(rod2.top());
        rod2.pop();
    }
    return true;
}

bool Board::moveFromThirdRod(char target) {
    if (rod3.empty()) {
        return false;
    }
    if ('1' == target) {
        if (!rod1.empty()) {
            if (rod3.top()->getSize() > rod1.top()->getSize()) {
                return false;
            }
        }
        rod1.push(rod3.top());
        rod3.pop();
    }
    if ('2' == target) {
        if (!rod3.empty()) {
            if (rod3.top()->getSize() > rod2.top()->getSize()) {
                return false;
            }
        }
        rod2.push(rod3.top());
        rod3.pop();
    }
    if ('3' == target) {
        return false;
    }
    return true;
}