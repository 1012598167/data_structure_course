#include <iostream>
#include "CirLinkList.h"


typedef int Node_entry; //声明一个新类型名来代替已有的类型名

using namespace std;

const int n=8,m=3;

int main()
{
    int n,m;
    cin>>n>>m;
    CirLinkList c;
    c.create_cirlinklist(n);
    int one_to_m=1;
    Node *temp=c.get_Head();
    while(c.length()>1)
    {
        if (one_to_m==m)
        {
            c.del(temp,0);
            one_to_m=1;
        }
        if (m!=1)//m=1的话再++就会无法进入if的条件
            one_to_m++;
        temp=temp->next;

    }
    c.print();
    return 0;
}


