//
// Created by mathskiller on 2018/12/1.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

void ShellSort(int A[], int n);
void print(int A[], int n);
void QuickSort(int A[],int left,int right);
int Partition(int A[], int left, int right);
void swap(int &a,int &b);
void msd_radix_sort(int A[],int begin,int end,int d);
void lsd_radix_sort(int A[],int begin,int end,int d);
int getdigit(int a,int d);
void Merge(int A[], int left, int mid, int right);
void MergeSortRecursion(int A[], int left, int right);
//低位写 高位 mergesort 堆排
#endif //SORT_SORT_H