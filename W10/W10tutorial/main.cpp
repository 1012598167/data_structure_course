#include <iostream>
//#include "heapsort.h"
#include "top_k.h"
int main()
{
    //
/*    Heapsort heap;
    heap.heap_sort(4);
    heap.print();*/
    //

    //
    Top_k heap;
    Coordinate a(1,0);
    Coordinate b(2,0);
    Coordinate c(0,3);
    heap.add(a);
    heap.get_top_k();
    heap.add(b);
    heap.get_top_k();
    heap.add(c);
    heap.get_top_k();
    //
    return 0;
}