#ifndef MYSTACK_H
#define MYSTACK_H


enum Error_code{underflow, overflow, success};
const int maxstack = 10;   //  small value for testing

template<class Stack_entry>
class MyStack {
public:
   MyStack();
   bool empty() const;
   Error_code push(const Stack_entry &item);
   Error_code pop();
   Error_code top(Stack_entry &item) const;

private:
   int count;
   Stack_entry entry[maxstack];
};

#endif // MYSTACK_H

#define MYSTACK_CPP
#include"src/MyStack.cpp"

