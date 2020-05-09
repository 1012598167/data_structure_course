#include <iostream>
 using namespace std;

 void swap5(int *&a, int *&b){
     delete a;
     a=NULL;
/*         int tem = *a;
         *a = *b;
         *b = tem;*/
     }

 int main(){
         int a = 1;
         int b = 2;

         int *aPtr = &a;
         int *bPtr = &b;
         int *&arPtr = aPtr;
         int *&brPtr = bPtr;

         swap5(arPtr, brPtr);

         cout<<"a = "<<a<<endl;
         cout<<"b = "<<b<<endl;
         system("pause");
         return 0;
     }