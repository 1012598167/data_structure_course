//
// Created by mathskiller on 2018/11/19.
//

//#ifndef QIZHONGDIER_STACK_H
//#define QIZHONGDIER_STACK_H

typedef int Stack_entry;

class MyIntStack
{
public:
    MyIntStack(int &n);
    ~MyIntStack();
    int push(const Stack_entry &item);
    bool empty() const;
    Stack_entry pop();
    int top(Stack_entry &item) const;
private:
    int count;
    int maxstack;
    Stack_entry *entry;
};


MyIntStack::MyIntStack(int &n)
{
    maxstack=n;
    entry=new Stack_entry[n];
    count=0;
}

MyIntStack::~MyIntStack()
{
    delete [] entry;
}

bool MyIntStack::empty() const
{
    return (count == 0);
}

int MyIntStack::push(const Stack_entry &item)
{
    entry[count]=item;
    count++;
    return 1;
}


Stack_entry MyIntStack::pop()
{
    if(empty())
        return -1;
    Stack_entry c;
    top(c);
    count--;
    return c;
}

int MyIntStack::top(Stack_entry &item) const
{
    if(empty())
        return 0;
    item=entry[count-1];
    return 1;
}


//#endif QIZHONGDIER_STACK_H
