#include "disk.h"

Disk::Disk(int size)
    : size(size)
{
}

Disk::~Disk()
{
}

int Disk::getSize() {
    return size;
}