#ifndef UTIL_CPP
#define UTIL_CPP

#include <random>

#include "util.h"

class Util : public Utilizable {
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

public:
    Util() 
        : gen(rd()),
        dis(0, 2)
    {}

    ~Util() {}

    milliseconds logTime() override {
        return duration_cast<milliseconds> (system_clock::now().time_since_epoch());
    }

    char randomTarget() override {
        char choices[] = {'1', '2', '3'};
        char random_choice = choices[dis(gen)];
        return random_choice;
    }
};

class UtilMock : public Utilizable {
    int firstMillis;
    int advancedMins;
    int callFrequency;

public:
    UtilMock(int firstMillis, int advancedMins)
        : firstMillis(firstMillis),
        advancedMins(advancedMins)
    {}
    
    ~UtilMock()
    {}
    
    milliseconds logTime() override {
        callFrequency++;
        if (callFrequency == 1) return milliseconds(firstMillis);
        if (callFrequency == 2) return milliseconds(advancedMins);
        return milliseconds(0);
    }
};

#endif