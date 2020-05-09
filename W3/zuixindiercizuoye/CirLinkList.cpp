//
// Created by mathskiller on 2018/10/8.
//

#include "CirLinkList.h"
#include<iostream>
CirLinkList::CirLinkList()
{
    Head=new Node;
    Tail=new Node;
    isempty= true;
    count=0;
}

CirLinkList::~CirLinkList()
{
    int lth=length();
    Node *temp=get_Head();
    Node *temp_next;
    while(lth--)
    {
        temp_next=temp->next;
        delete temp;
        temp= NULL;
        temp=temp_next;
    }
}

int CirLinkList::create_cirlinklist(int n)
{
    int tempn=n;
    int xh=1;
    while (tempn--)
    {
        add_from_tail(xh++);
    }
    xh--;
    return 0;
}

int CirLinkList::add_from_head(Node_entry item)
{
    Node* temp=new Node(item);
    if (isempty)
    {
        Head=temp;
        Tail=temp;
        Head->next=Head;
        Tail->next=Tail;
    }
    else
    {
        Tail->next=temp;
        temp->next=Head;
        Head=temp;
    }
    return item;
}

int CirLinkList::add_from_tail(Node_entry item)
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

void CirLinkList::print()
{
    Node *Head_NOW=get_Head();
    Node *temp=Head_NOW;
    do
    {
        std::cout<<temp->entry<<std::endl;
        temp=temp->next;
    }while (temp!=Head_NOW);
}

void CirLinkList::del(Node *&node, int m)
{
    Node *to_del=node;
    while(m--)
    {
        to_del=to_del->next;
    }
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

}

Node *CirLinkList::get(Node *node, int index)
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

int CirLinkList::length()
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

Node *CirLinkList::get_Head()
{
    return Head;
}

Node::Node()
{
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on)
{
    entry = item;
    next = add_on;
}
