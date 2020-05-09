#include <iostream>
#include "heapsort.h"
int main()
{
    heapsort heap1;
    //heap_array b[4]={Node(1,2),Node(1,3),Node(3,2),Node(4,1)};
    heap_array*a=new heap_array[4];
    a[0]=Node(3,2);
    a[1]=Node(1,3);
    a[2]=Node(1,2);
    a[3]=Node(4,1);
    //heap1.Build_Heap(a,4);
    heap1.Heapsort(a,4);
    cout << "Hello, World!" <<endl;
    heapsort heap2;
    int i=0;
    while(i<=3)
    {
        heap2.add(a[i++]);
        heap2.get_topk();
        cout<<endl;
    }
    return 0;
}