#include <iostream>
#include <map>
#include "Sort.h"
using namespace std;
int main() {
    Sort s;
    s.creat();
    s.print();
//    s.MergeSort();
    s.Print(s.insertionSortList(s.getHaed()));
    return 0;
}