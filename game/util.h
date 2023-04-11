#ifndef UTIL_H
#define UTIL_H

#include <chrono>

using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;

class Utilizable
{
public:
    virtual ~Utilizable() {};
    virtual milliseconds logTime() = 0;
    virtual int randomTarget() = 0;
};

#endif