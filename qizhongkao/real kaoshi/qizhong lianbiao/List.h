//
// Created by mathskiller on 2018/11/19.
//

#ifndef QIZHONG_LIANBIAO_LIST_H
#define QIZHONG_LIANBIAO_LIST_H
#include "stdio.h"
using namespace std;
typedef int Node_entry;
struct Lnode
{
    Node_entry entry;
    Lnode *next;
    Lnode();
    Lnode(Node_entry item, Lnode *add_on=NULL);
}lnode,*linklist;
class List
{
public:
    List();
    ~List();
    void create_auto(int n);
    int del(int m);

private:
    Lnode* Head;
    Lnode* Tail;
    int count;
};


Lnode::Lnode()
{
    next = NULL;
}

Lnode::Lnode(Node_entry item, Lnode *add_on)
{
    entry = item;
    next = add_on;
}

List::List()
{
    Head=new Lnode;
    Tail=new Lnode;
    count=0;
}

List::~List()
{
    int lth=count;
    Lnode *temp=Head;
    Lnode *temp_next;
    while(lth--)
    {
        temp_next=temp->next;
        delete temp;
        temp= NULL;
        temp=temp_next;
    }
}

void List::create_auto(int n)
{
    int xh=1;
    for (int i=1;i<=n;i++)
    {
        Lnode* temp=new Lnode(i);
        if(i==1)
        {
            Tail=temp;
            Head=Tail;
        }
        else if(i==2)
        {
            Tail->next=temp;
            Tail=temp;
            Head->next=Tail;
        }
        else
        {
            Tail->next=temp;
            Tail=temp;
        }
        count++;
    }
}

int List::del(int m)
{
    if (count==0)
        return -1;
    m=count-m;
    Lnode * node=Head;
    Lnode *to_del=Head;
    while(m--)
    {
        to_del=to_del->next;
    }
    int entr=to_del->entry;
    Lnode* formal=new Lnode;
    while(node->entry!=entr)
    {
        node=node->next;
    }
    formal=node;
    formal->next=to_del->next;
    delete to_del;
    to_del=NULL;
    count--;
    return entr;
}


#endif //QIZHONG_LIANBIAO_LIST_H
