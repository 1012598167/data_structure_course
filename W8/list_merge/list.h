//
// Created by mathskiller on 2018/12/18.
//

#ifndef LIST_MERGE_LIST_H
#define LIST_MERGE_LIST_H

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


#endif //LIST_MERGE_LIST_H
