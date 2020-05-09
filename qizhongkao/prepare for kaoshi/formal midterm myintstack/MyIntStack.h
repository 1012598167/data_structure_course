//
// Created by mathskiller on 2018/11/18.
//

#ifndef FORMAL_MIDTERM_MYINTSTACK_MYINTSTACK_H
#define FORMAL_MIDTERM_MYINTSTACK_MYINTSTACK_H

typedef int Stack_entry;

class MyIntStack
{
public:
    MyIntStack(int &n);
    ~MyIntStack();
    bool empty() const;
    bool full() const;
    int push(const Stack_entry &item);
    int pop();
    int top(Stack_entry &item) const;
    int getMin() const;
private:
    int count;
    int maxstack;
    Stack_entry *entry;
};


#endif //FORMAL_MIDTERM_MYINTSTACK_MYINTSTACK_H
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

bool MyIntStack::full() const
{
    return (count == maxstack-1);
}

int MyIntStack::push(const Stack_entry &item)
{
    if (full())
        return 0;
    entry[count]=item;
    count=((count+1)==maxstack)?0:(count+1);
    return 1;
}


int MyIntStack::pop()
{
    if(empty())
        return -1;
    Stack_entry c;
    top(c);
    count=((count-1)==-1)?(maxstack-1):(count-1);
    return c;
}

int MyIntStack::top(Stack_entry &item) const
{
    if(empty())
        return 0;
    item=entry[count-1];
    return 1;
}

int MyIntStack::getMin() const
{
    int item;
    if(empty())
        return -1;
    int min=entry[0];
    for (int i = 0; i < count-1; i++)
    {
        min=(entry[i+1]<min)?entry[i+1]:min;
    }
    item=min;
    return item;
}

