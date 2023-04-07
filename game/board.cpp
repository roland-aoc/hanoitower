#include "board.h"

#include <algorithm>

using std::for_each;
using std::begin;
using std::end;

Board::Board(/* args */)
{
}

Board::~Board()
{
}

void Board::startingPos(int difficulty) {
    startSize = difficulty;
    for (int i = 0; i < difficulty; i++) {
        rod1.push_back(new Disk(i));
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
            if (rod1.back()->getSize() > rod2.back()->getSize()) {
                return false;
            }
        }
        rod2.push_back(rod1.back());
        rod1.pop_back();
    }
    if ('3' == target) {
        if (!rod3.empty()) {
            if (rod1.back()->getSize() > rod3.back()->getSize()) {
                return false;
            }
        }
        rod3.push_back(rod1.back());
        rod1.pop_back();
    }
    return true;
}

bool Board::moveFromSecondRod(char target) {
    if (rod2.empty()) {
        return false;
    }
    if ('1' == target) {
        if (!rod1.empty()) {
            if (rod2.back()->getSize() > rod1.back()->getSize()) {
                return false;
            }
        }
        rod1.push_back(rod2.back());
        rod2.pop_back();
    }
    if ('2' == target) {
        return false;
    }
    if ('3' == target) {
        if (!rod3.empty()) {
            if (rod2.back()->getSize() > rod3.back()->getSize()) {
                return false;
            }
        }
        rod3.push_back(rod2.back());
        rod2.pop_back();
    }
    return true;
}

bool Board::moveFromThirdRod(char target) {
    if (rod3.empty()) {
        return false;
    }
    if ('1' == target) {
        if (!rod1.empty()) {
            if (rod3.back()->getSize() > rod1.back()->getSize()) {
                return false;
            }
        }
        rod1.push_back(rod3.back());
        rod3.pop_back();
    }
    if ('2' == target) {
        if (!rod3.empty()) {
            if (rod3.back()->getSize() > rod2.back()->getSize()) {
                return false;
            }
        }
        rod2.push_back(rod3.back());
        rod3.pop_back();
    }
    if ('3' == target) {
        return false;
    }
    return true;
}

bool Board::hasWon() {
    if (rod3.size() == startSize) {
        return true;
    }
    // spdlog::get("logger")->info("has not won...");
    return false;
}

string& Board::getStatus() {
    // for (int i = 0; i < rod1.size(); i++) {
    //     status.append(rod1.()-i; disk->getSize());
    // }
    status.clear();
    status.append("Rod1: ");
    for_each(rod1.begin(), rod1.end(), [this](Disk* disk){ status.append(std::to_string(disk->getSize())); status.append(", "); });
    status.append("\n--------------------\n");
    status.append("Rod2: ");
    for_each(rod2.begin(), rod2.end(), [this](Disk* disk){ status.append(std::to_string(disk->getSize())); status.append(", "); });
    status.append("\n--------------------\n");
    status.append("Rod3: ");
    for_each(rod3.begin(), rod3.end(), [this](Disk* disk){ status.append(std::to_string(disk->getSize())); status.append(", "); });
    status.append("\n--------------------\n");
    return status;
}