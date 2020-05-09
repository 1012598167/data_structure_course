#include <iostream>
#include"Coord.h"

using namespace std;

int main()
{
    Coord c1(1,1);
    Coord c2(2,2);

    //Check operator +
    //Check the copy constructor
    Coord c3=c1+c2;
    c3.Print();

    //Check operator =
    c2=c3;
    c2.Print();

    //Check operator -
    --c2;
    c2.Print();

    //Check operator <<
    cout<<c2<<endl;


    cout<<"Test Extend Class"<<endl;
    Rect rect(1,1,2,2);
   // rect.isZero();
    rect.TestMembers();
    rect.Print();


    return 0;
}
