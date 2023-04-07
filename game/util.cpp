#ifndef UTIL_CPP
#define UTIL_CPP

#include "util.h"

class Util : public Utilizable {
public:
    Util() {}
    ~Util() {}
    milliseconds logTime() override {
        return duration_cast<milliseconds> (system_clock::now().time_since_epoch());
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