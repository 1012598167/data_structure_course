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
    while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
        if (son + 1 <= end && arr[son + 1] > arr[son]) //�ȱȽ������ӽڵ��С��ѡ������
            son++;
        if (arr[dad] > arr[son]) //������ڵ����ӽڵ���������ϣ�ֱ����������
            return;
        else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void Heapsort::heap_sort(int len)
{
    //��ʼ����i������һ�����ڵ㿪ʼ����
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(i, len - 1);
    //�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
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
