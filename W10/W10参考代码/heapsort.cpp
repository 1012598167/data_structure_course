#include "heapsort.h"
#include <iostream>
#include <algorithm>
using namespace std;

Heapsort::Heapsort()
{
    int n=0;
    int x=0;
    int y=0;
    cout<<"please input the size of array:";
    cin>>n;
    count = n;
    for(int i=0; i<count; i++)
    {
        cout<<"please input the "<<i+1<<"th coordinate:";
        cin>>x>>y;
        arr[i] = Coordinate(x,y);
    }
}

void Heapsort::max_heapify(int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son + 1] > arr[son]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void Heapsort::heap_sort(int len)
{
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(0, i - 1);
    }
}


void Heapsort::print()
{
    for (int i = 0; i < count; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
