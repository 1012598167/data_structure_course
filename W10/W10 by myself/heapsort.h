//
// Created by mathskiller on 2018/12/24.
//

#ifndef W10_BY_MYSELF_HEAPSORT_H
#define W10_BY_MYSELF_HEAPSORT_H
const int max_size=30;
#include <iostream>
using namespace std;

struct Node
{
    Node();
    Node(int a,int b);
    int x_;
    int y_;
};



typedef  Node heap_array;

class heapsort
{
public:
    heapsort(int c=2);
    ~heapsort();
    heap_array Heap_Extract_Max(heap_array*&A);//返回并删除最大元素并保持堆
    void Heapify(heap_array*&A,int i,int num);//从第i个元素开始堆化//是指除了这个元素外其他元素都满足上面大于下面//o(lgn)
    //所以对于一个乱序的完全二叉树来说 从第一个元素到第n个元素用一遍Heapify就能成为堆
    //num=n in normal section num=k in topk
    void Build_Heap(heap_array array[],int size);//o(nlgn)
    void Heapsort(heap_array*&A,int size);//o(nlgn) main //排完node[]是乱序 而且n=0 这只用来输出结果
    void Heap_insert(heap_array key);
    int get_size();
    void add(heap_array a);
    void get_topk();
    heap_array*  node;
private:

    int n;//size
    int k;
};


#endif //W10_BY_MYSELF_HEAPSORT_H
