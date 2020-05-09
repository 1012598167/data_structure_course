//
// Created by mathskiller on 2018/10/7.
//

#ifndef DIERCIZUOYE_MYINTSTACK_H
#define DIERCIZUOYE_MYINTSTACK_H

enum Error_code{underflow, overflow, success};
template<class Stack_entry>
class MyIntStack
{
public:
    MyIntStack(int &n);
    ~MyIntStack();
    bool empty() const;
    bool full() const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    Error_code top(Stack_entry &item) const;
private:
    int count;
    int front;
    int rear;
    int maxqueue;
    Stack_entry *entry;

};

template<class Stack_entry>
MyIntStack<Stack_entry>::MyIntStack(int &n)
{
    maxqueue=n;
    entry = new Stack_entry [maxqueue];
    count=0;
    rear = maxqueue - 1;
    front = 0;
}

template<class Stack_entry>
MyIntStack<Stack_entry>::~MyIntStack()
{
    delete [] entry;
}


template<class Stack_entry>
bool MyIntStack<Stack_entry>::empty() const
{
    bool emp=false;
    if (count==0)
        emp= true;
    return emp;
}

template<class Stack_entry>
bool MyIntStack<Stack_entry>::full() const
{
    bool emp=false;
    if (count==maxqueue)
        emp= true;
    return emp;
}

template<class Stack_entry>
Error_code MyIntStack<Stack_entry>::push(const Stack_entry &item)
{
    if (full()==true)
        return overflow;
    else
    {
        count++;
        rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
        entry[rear] = item;
        return success;
    }
}

template<class Stack_entry>
Error_code MyIntStack<Stack_entry>::pop()
{
    if (empty()==true)
        return underflow;
    else
    {
        count--;
        front = ((front + 1) == maxqueue) ? 0 : (front + 1);
        return success;
    }
}

template<class Stack_entry>
Error_code MyIntStack<Stack_entry>::top(Stack_entry &item) const
{
    if (empty()==true)
        return underflow;
    else
    {
        item=entry[front];
        return success;
    }
}

#endif //DIERCIZUOYE_MYINTSTACK_H
