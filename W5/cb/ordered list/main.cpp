  #include <iostream>
//#include "List.cpp"//����ģ��.cpp��Ȼ.h����
//#include "Key.cpp"
//#include "Record.h"
  #include "Ordered_list.h"//�ҵ������˶���һ������ ������ᱨ�ض���Ĵ���û�ܽ��
using namespace std;

int main()
{
 /*   //��0��ʼ��
    List<int> list;
    int x=3;
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
    cout<<list.size()<<endl;//=0*/

    Ordered_list list_ordered;
/*    cout<<list_ordered.empty()<<endl;//is empty
    Record record(3,4);//key=3,other=4
    list_ordered.insert(record);*/

    return 0;
}
