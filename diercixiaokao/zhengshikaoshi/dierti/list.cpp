//
// Created by mathskiller on 2018/12/29.
//

#include "list.h"
#include <iostream>
using namespace std;
Node::Node()
{
    next = NULL;
}

Node::Node(Node_entry item, Node *add_on)
{
    entry = item;
    next = add_on;
}

void list::merge_sort()
{
    merge_sort_recurtion(Head);
}

void list::merge_sort_recurtion(Node *&sub_list)
{
    if (sub_list==NULL or sub_list->next==NULL)
        return;
    else
    {
        Node* half=devide(sub_list);
        merge_sort_recurtion(sub_list);
        merge_sort_recurtion(half);
        sub_list=merge(sub_list,half);
    }
}

Node* list::merge(Node *first, Node *second)
{
    Node* dumb_node=new Node;
    Node* temp_dumb_node=dumb_node;
    while(first!=NULL and second!=NULL)
    {
        if(first->entry<=second->entry)
        {
            temp_dumb_node->next=first;
            first=first->next;
            temp_dumb_node=temp_dumb_node->next;
        }
        else
        {
            temp_dumb_node->next=second;
            second=second->next;
            temp_dumb_node=temp_dumb_node->next;
        }
    }
    if (first==NULL)
    {
        temp_dumb_node->next=second;
    }
    else
    {
        temp_dumb_node->next=first;
    }
    return dumb_node->next;
}

list::list()
{
Head=NULL;
Tail=NULL;
}

void list::append(Node *node)
{
    if(Head==NULL)
    {
        Head=node;
        Tail=Head;
    }
    else
    {
        Tail->next=node;
        Tail=node;
    }
}

Node *list::devide(Node *&sub_list)
{
    Node*temp=sub_list;
    Node* half=temp;
    Node* pre_half=NULL;
    while ((temp=temp->next)!=NULL)
    {
        pre_half=half;
        half=half->next;
        temp=temp->next;
        if(temp==NULL)
            break;
    }
    if (pre_half!=NULL)
        pre_half->next=NULL;
    return half;
}

void list::print()
{
    Node* node=get_head();
    while(node!=NULL)
    {
        cout<<node->entry.the_record()<<" ";
        node=node->next;
    }
}

void list::Print(Node *q)
{
    Node *p=q;
    while (p!= NULL)
    {
        cout<<p->entry.the_record()<<" ";
        p=p->next;
    }
    cout<<endl;
}

Node * list::insertionSortList(Node *head)
{
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(head == NULL || head->next == NULL)return head;
    Node *p = head->next, *pstart = new Node(0), *pend = head;
    pstart->next = head; //为了操作方便，添加一个头结点
    while(p != NULL)
    {
        Node *tmp = pstart->next, *pre = pstart;
        while(tmp != p &&  tmp->entry<=p->entry) //找到插入位置
            {tmp = tmp->next; pre = pre->next;}
        if(tmp == p)pend = p;
        else
        {
            pend->next = p->next;
            p->next = tmp;
            pre->next = p;
        }
        p = pend->next;
    }
    head = pstart->next;
    delete pstart;
    return head;
}