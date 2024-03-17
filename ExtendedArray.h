#include <iostream>
#include <random>
#include <algorithm>

#ifndef EXTENDEDARRAY_H
#define EXTENDEDARRAY_H

#pragma once

class ExtendedArray
{
public:
    ExtendedArray(int arrL);
    int getCount();
    int getAt(int i);
    void setAt(int att);
    void printArr();
    ExtendedArray * merge (ExtendedArray * array);
    ExtendedArray * intersect(ExtendedArray * array);
    void fillWithRandomNumbers(int min, int max);
    ~ExtendedArray();

private:
    int * numArray;
    int arrayLen;
    int itemCount;
};

#endif