//
// Created by mathskiller on 2018/12/23.
//

#ifndef W10TUTORIAL_HEAPSORT_H
#define W10TUTORIAL_HEAPSORT_H

#include "coordinate.h"
const int max_size = 30;

class Heapsort
{
public:
    Heapsort();
    void max_heapify(int start, int end);
    void heap_sort(int len);
    void print();
private:
    Coordinate arr[max_size];
    int count;
};



#endif //W10TUTORIAL_HEAPSORT_H
