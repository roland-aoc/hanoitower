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

    milliseconds logTime() override {
        return duration_cast<milliseconds> (system_clock::now().time_since_epoch());
    }

    int randomTarget() override {
        int choices[] = {1,2,3};
        return choices[dis(gen)];
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
    
    milliseconds logTime() override {
        callFrequency++;
        if (callFrequency == 1) return milliseconds(firstMillis);
        if (callFrequency == 2) return milliseconds(advancedMins);
        return milliseconds(0);
    }
    
    int randomTarget() override {
        return 1;
    }
};

#endif