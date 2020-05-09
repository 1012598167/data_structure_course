//
// Created by mathskiller on 2018/11/18.
//

#ifndef FORMAL_MIDTERM_LIST_LIST_H
#define FORMAL_MIDTERM_LIST_LIST_H

#include "stdio.h"
using namespace std;
typedef int Node_entry;
struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item, Node *add_on=NULL);
}node,*linklist;
class List
{
public:
    List();
    ~List();
    int create_cirlinklist_auto(int n);
    int add_from_tail(Node_entry item);  //尾插
    void print();    //打印链表中所有节点的entry
    void insert(int a,int b);
    int del(Node* &node, int m);  //从节点node开始删除第m个节点
    Node* get(Node* node, int index); //从节点node开始查找第m个节点
    int length();  //获取链表长度
    void clear();
    Node* get_Head();
private:
    Node* Head;
    Node* Tail;
    int count;
    bool isempty;
};


#endif //FORMAL_MIDTERM_LIST_LIST_H
Node::Node()
{
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on)
{
    entry = item;
    next = add_on;
}

List::List()
{
    Head=new Node;
    Tail=new Node;
    isempty= true;
    count=0;
}

List::~List()
{
    int lth=length();
    Node *temp=Head;
    Node *temp_next;
    while(lth--)
    {
        temp_next=temp->next;
        delete temp;
        temp= NULL;
        temp=temp_next;
    }
}

int List::create_cirlinklist_auto(int n)
{
    int tempn=n;
    int xh=1;
    while (tempn--)
    {
        add_from_tail(xh++);
    }
    xh--;
    return 1;
}

int List::add_from_tail(Node_entry item)
{
    Node* temp=new Node(item);
    if (isempty)
    {
        Tail=temp;
        Tail->next=Tail;
        Head=Tail;
        isempty= false;
    }
    else
    {
        temp->next=Tail->next;
        Tail->next=temp;
        Tail=temp;
        Head=Tail->next;
    }

    return item;
}

void List::print()
{
    Node *temp=Head;
    do
    {
        cout<<temp->entry<<endl;
        temp=temp->next;
    }while (temp!=Head);
}

void List::insert(int a,int b)
{
    Node *temp_Now=Head;
    while(--a)
    {
        temp_Now=temp_Now->next;
    }
    Node *form=get(temp_Now,length()-1);
    Node* insert=new Node(b);
    insert->next=temp_Now;
    form->next=insert;
}

int List::del(Node * &node, int m)
{
    Node *to_del=node;
    while(m--)
    {
        to_del=to_del->next;
    }
    int entr=to_del->entry;
    if (!isempty)
    {
        if (to_del->next==to_del)
        {
            delete Head;
            delete Tail;
            Head=NULL;
            Tail=NULL;
            node=NULL;
            isempty= true;
        }
        else
        {
            if (to_del==Head)
            {
                Tail->next=Head->next;
                node=to_del->next;
                delete Head;
                Head=NULL;
                Head=Tail->next;
            }
            else if(to_del==Tail)
            {
                Node *pre_to_del=get(to_del,length()-1);
                pre_to_del->next=Head;
                node=to_del->next;
                delete Tail;
                Tail=NULL;
                Tail=pre_to_del;
            }
            else
            {
                Node *pre_to_del=get(to_del,length()-1);
                pre_to_del->next=to_del->next;
                node=to_del->next;
                delete to_del;
                to_del=NULL;
            }

        }
    }
    return entr;
}

Node *List::get(Node *node, int index)
{
    if (isempty)
    {
        return NULL;
    }
    else
    {
        Node *to_get=node;
        while(index--)
        {
            to_get=to_get->next;
        }
        return to_get;
    }
}

int List::length()
{
    int count=0;
    if (isempty)
        return 0;
    Node *Head_NOW=Head;
    Node *temp=Head_NOW;
    do
    {
        count++;
        temp=temp->next;
    }while (temp!=Head_NOW);
    return count;
}

void List::clear()
{
    int lth=length();
    Node *temp=Head;
    Node *temp_next;
    while(lth--)
    {
        temp_next=temp->next;
        delete temp;
        temp= NULL;
        temp=temp_next;
    }
}

Node *List::get_Head()
{
    return Head;
}
