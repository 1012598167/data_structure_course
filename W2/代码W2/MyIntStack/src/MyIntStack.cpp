#include "MyIntStack.h"

MyIntStack::MyIntStack()
{
    //ctor
    count=0;
}

MyIntStack::~MyIntStack()
{
    //dtor
}

bool MyIntStack::empty() const{

   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}

Error_code MyIntStack::push(const int &item){

   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}


Error_code MyIntStack::pop(){
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


Error_code MyIntStack::top(int &item)  const  //Read

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}
