#include <iostream>
#include "list.h"
int main()
{
    Record record[10]={36,5,16,98,95,47,32,36,48,10};
    list alist;
    for (int i=0;i<10;i++)
    {
        Node* node=new Node(record[i]);
        alist.append(node);
    }
    //alist.merge_sort();
    alist.Print(alist.insertionSortList(alist.get_head()));
    //alist.print();
    return 0;
}


