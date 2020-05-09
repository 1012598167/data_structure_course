
//#include "List.cpp"//用了模板.cpp不然.h就行
//#include "Key.cpp"
//#include "Record.h"
#include "Ordered_list.h"


int main()
{
    //以0开始！
    List<int> list;
    int x;
    cout<<list.empty()<<endl;//is empty
    for (int i = 0; i < max_list; i++)
    {
        list.insert(i,i);
    }//fill list for 0 to 29
    cout<<list.full()<<endl;//is full
    list.remove(0,x);//remove 0
    cout<<list.size()<<endl;//size
    list.replace(3,x);//replace po3 by 0
    list.retrieve(3,x);
    cout<<"x="<<x<<endl;//x=?
    list.clear();
    cout<<list.size()<<endl;//=0

/*    Ordered_list list_ordered;
    cout<<list_ordered.empty()<<endl;//is empty
    Record record(3,4);//key=3,other=4
    list_ordered.insert(record);*/

    Key target(5);
    Ordered_list mylist;
    for(int i=0; i<10; i++) mylist.insert(Record(i,10));
    int bottom=0;
    int top=mylist.size()-1;
    int position=-1;
    if(mylist.recursive_binary(mylist, target, bottom, top, position)==success)
        cout<<"Get the target in position: " << position <<endl;
    else
        cout<<"Target not present."<<endl;

    return 0;
}