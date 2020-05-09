//
// Created by mathskiller on 2018/12/23.
//

#ifndef W10TUTORIAL_TOP_K_H
#define W10TUTORIAL_TOP_K_H

#include <iostream>
#include "coordinate.h"
#include <algorithm>
using namespace std;

const int max_size = 30;

class Top_k {
public:
    Top_k();
    void max_heapify(int start, int end);
    void add(Coordinate a);
    void get_top_k();
private:
    Coordinate nums[max_size];
    int count;
    int k;
};


#endif //W10TUTORIAL_TOP_K_H
