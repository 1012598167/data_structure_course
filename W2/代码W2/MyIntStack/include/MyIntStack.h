#ifndef MYINTSTACK_H
#define MYINTSTACK_H


enum Error_code{underflow, overflow, success};
const int maxstack = 10;   //  small value for testing

class MyIntStack
{
    public:
        MyIntStack();
        virtual ~MyIntStack();
        MyStack();
        bool empty() const;
        Error_code push(const int &item);
        Error_code pop();
        Error_code top(int &item) const;

    private:

        int count;
        int entry[maxstack];

};

#endif // MYINTSTACK_H
