//
// Created by yinzh on 2018/11/26.
//

#ifndef HOMEWORK8_SORT_H
#define HOMEWORK8_SORT_H
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){ }
    ListNode(){ }
}NODE;

class Sort {
public:
    Sort();
    ~Sort();
    void creat();
    void print();
    void Print(NODE *q);
    void MergeSort();
    NODE *mergeSortList(NODE *head);
    NODE *merge(NODE *head1, NODE *head2);
    ListNode *insertionSortList(ListNode *head);
    NODE *getHaed();
private:
    NODE* Head;
    int count;
};


#endif //HOMEWORK8_SORT_H
