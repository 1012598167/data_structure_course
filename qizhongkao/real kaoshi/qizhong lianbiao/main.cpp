#include <iostream>
#include "List.h"

int main()
{
    int a;
    cin>>a;
    List list;
    list.create_auto(5);
    if (a<=0 || a>=6)
        cout<<-1<<endl;
    else
        cout<<list.del(a)<<endl;
    return 0;
}