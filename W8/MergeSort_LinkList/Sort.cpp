//
// Created by yinzh on 2018/11/26.
//
#include <iostream>
#include "Sort.h"
using namespace std;
Sort::Sort() {
    Head= nullptr;
    count=0;
}

Sort::~Sort() {
    int i;
    NODE *p=Head;
    NODE *q;
    for(i=0;i<count;i++){
        q=p;
        p=p->next;
        delete [](q);
    }
    Head= nullptr;
}

void Sort::creat() {
    int i;
    NODE *p=new NODE;
    Head=p;
    NODE *q;
    cout<<"******LinkList MergeSort******"<<endl;
    cout<<"Please tell me the number of digits you want to input:"<<endl;
    cin>>count;
    cout<<"Please input the numbers:"<<endl;
    cin>>p->val;
    for(i=1;i<count;i++){
        q=new NODE;
        p->next=q;
        cin>>q->val;
        p=q;
    }
    p->next= nullptr;
}

void Sort::print() {
    NODE *p=Head;
    while (p!= nullptr){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

NODE *Sort::mergeSortList(NODE *head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    else{
        NODE *fast = head,*slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){//快慢指针找到中间节点
            fast = (fast->next)->next;
            slow = slow->next;
        }
        NODE *p1,*p2;
        p1 = slow;
        p2 = slow->next;
        p1->next=nullptr;
        p1 = mergeSortList(head);//前半段排序
        p2 = mergeSortList(p2);//后半段排序
        return  merge(p1,p2);
    }
}

NODE *Sort::merge(NODE *head1, NODE *head2) {
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }
    NODE *p,*q ;
    if(head1->val < head2->val){
        q = head1;
        head1 = head1->next;
    }
    else{
        q = head2;
        head2 = head2->next;
    }
    p = q;
    while(head1 != nullptr && head2 != nullptr)
    {
        if(head1->val < head2->val)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if (head1 != nullptr){
        p->next = head1;
    }
    if (head2 != nullptr){
        p->next = head2;
    }
//    cout<<"print all:";
//    print();
//    cout<<"print merge:";
//    Print(q);
    return q;
}

NODE *Sort::getHaed() {
    return Head;
}

void Sort::Print(NODE *q) {
    NODE *p=q;
    while (p!= nullptr){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

void Sort::MergeSort() {
    NODE *p=mergeSortList(Head);
    Head=p;
    Print(p);
}

ListNode *Sort::insertionSortList(ListNode *head) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(head == nullptr || head->next == nullptr)return head;
    ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
    pstart->next = head; //为了操作方便，添加一个头结点
    while(p != nullptr)
    {
        ListNode *tmp = pstart->next, *pre = pstart;
        while(tmp != p && p->val >= tmp->val) //找到插入位置
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
    Head=head;
    delete pstart;
    return head;
}



