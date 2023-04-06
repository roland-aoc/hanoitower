#ifndef DISK_H
#define DISK_H

#include "../config.h"
#include "spdlog/spdlog.h"

class Disk
{
int size;

public:
    Disk(int);
    ~Disk();
    int getSize();
};

#endif