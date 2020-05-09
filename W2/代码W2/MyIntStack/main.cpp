#include <iostream>
#include "MyIntStack.h"

using namespace std;

int main()
{
    int n;
   int item;
   MyIntStack numbers;  //  declares and initializes a stack of numbers
   cout << " Type in an integer n followed by n integer numbers." << endl
        << " The numbers will be printed in reverse order." << endl;
   cin  >> n;
   for (int i = 0; i < n; i++) {
      cin >> item;
      numbers.push(item);  //将item入栈
   }
   cout << endl << endl;
   while (!numbers.empty()) {
       numbers.top (item);  //访问栈顶元素
       cout << item << " ";
       numbers.pop();   //出栈
   }
   cout << endl;

    return 0;
}
