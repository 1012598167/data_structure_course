//
// Created by mathskiller on 2018/12/29.
//

#ifndef DISANTI_LIST_H
#define DISANTI_LIST_H


#include "Record.h"
typedef Record Node_entry;
struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item, Node *add_on= NULL);
};

class list
{
public:
    list();
    void append(Node* node);
    void merge_sort();
    void merge_sort_recurtion(Node* &sub_list);
    Node* merge(Node* first,Node* second);
    Node* devide(Node* &sub_list);
    void print();
    void Print(Node *q);
    Node* get_head(){ return Head;}
    Node *insertionSortList(Node *head);
private:
    Node* Head;
    Node* Tail;
};


#endif //DISANTI_LIST_H
