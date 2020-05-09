#include <iostream>
#include "MyIntStack.h"

using namespace std;

int main()
{
    int n;
    Error_code a,b;
    int item;

    cout << " Type in an integer n followed by n integer numbers." << endl
         << " The numbers will be printed in reverse order." << endl;
    cin  >> n;
    MyIntStack<int> numbers(n);  //  declares and initializes a stack of numbers
    for (int i = 0; i < n; i++) {
        cin >> item;
        numbers.push(item);  //将item入栈
    }
    cout << endl << endl;
    while (!numbers.empty()) {
        a=numbers.top (item);
        if (a==success){}
        else
        {
            cout << a << " ";
            break;
        }//访问栈顶元素
        cout << item << " ";
        b=numbers.pop();
        if (b==success) {}
        else
        {
            cout << b <<"";
            break;
        }   //出栈
    }
    cout << endl;

    return 0;
}
