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
      numbers.push(item);  //��item��ջ
   }
   cout << endl << endl;
   while (!numbers.empty()) {
       numbers.top (item);  //����ջ��Ԫ��
       cout << item << " ";
       numbers.pop();   //��ջ
   }
   cout << endl;

    return 0;
}
