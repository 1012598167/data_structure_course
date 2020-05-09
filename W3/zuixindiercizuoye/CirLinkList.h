//
// Created by mathskiller on 2018/10/8.
//

#ifndef ZUIXINDIERCIZUOYE_CIRLINKLIST_H
#define ZUIXINDIERCIZUOYE_CIRLINKLIST_H

#include <crtdbg.h>

typedef int Node_entry;
struct Node
{
    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item, Node *add_on=NULL);
};

class CirLinkList
{
public:
    CirLinkList();
    ~CirLinkList();   //动态分配,堆内存,程序员分配释放
    int create_cirlinklist(int n);
    int add_from_head(Node_entry item);  //头插
    int add_from_tail(Node_entry item);  //尾插
    void print();    //打印链表中所有节点的entry
    void del(Node* &node, int m);  //从节点node开始删除第m个节点
    Node* get(Node* node, int index); //从节点node开始查找第m个节点
    int length();  //获取链表长度
    Node* get_Head();  //获取头指针
private:
    Node* Head;
    Node* Tail;
    int count;
    bool isempty;
};




#endif //ZUIXINDIERCIZUOYE_CIRLINKLIST_H
