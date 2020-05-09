//
// Created by mathskiller on 2018/11/18.
//

#ifndef FORMAL_MIDTERM_CIRQUEUE_CIRQUEUE_H
#define FORMAL_MIDTERM_CIRQUEUE_CIRQUEUE_H

typedef int Queue_entry;
class CirQueue
{
public:
    CirQueue(int &n);
    ~CirQueue();
    bool empty() const;
    bool full() const;
    int push(const Queue_entry &item);
    int pop();
    int top(Queue_entry &item) const;
private:
    int count;
    int front;
    int rear;
    int maxqueue;
    Queue_entry *entry;
};


CirQueue::CirQueue(int &n)
{
    maxqueue=n;
    count=0;
    entry=new Queue_entry[maxqueue];
    front=0;
    rear=maxqueue-1;
}

CirQueue::~CirQueue()
{
    delete [] entry;
}

bool CirQueue::empty() const
{
    return (count==0);
}

bool CirQueue::full() const
{
    return (count==maxqueue);
}

int CirQueue::push(const Queue_entry &item)
{
    if (full())
        return -1;
    count++;
    rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
    entry[rear] = item;
    return 1;

}

int CirQueue::pop()
{
    if (empty())
        return -1;
    else
    {
        Queue_entry c;
        top(c);
        count--;
        front = ((front + 1) == maxqueue) ? 0 : (front + 1);
        return c;
    }
}

int CirQueue::top(Queue_entry &item) const
{
    if(empty())
        return -1;
    item=entry[front];
    return entry[front];
}

#endif //FORMAL_MIDTERM_CIRQUEUE_CIRQUEUE_H