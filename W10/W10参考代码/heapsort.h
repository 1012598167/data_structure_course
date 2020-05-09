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


