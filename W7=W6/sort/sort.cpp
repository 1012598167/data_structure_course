//
// Created by mathskiller on 2018/12/1.
//
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
void ShellSort(int A[], int n)
{
    int length=n;
    n/=2;
    while (n>1)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=i+n;j<length;j+=n)
            {
                int sentry=A[j];
                int k=j-n;
                while(sentry<A[k] && k>=0)
                {
                    A[k+n]=A[k];
                    k-=n;
                }
                A[k+n]=sentry;
            }
        }
        n/=2;
    }
}

void print(int A[], int n)
{
    cout<<"A=[";
    for (int i=0;i<n-1;i++)
        cout<<A[i]<<",";
    cout<<A[n-1]<<"]"<<endl;
}

int Partition(int A[], int left, int right,int mark)
{
    if (left==right) return left;
    else if (A[left]>A[right] && mark%2==0)
    {
        swap(A[left],A[right]);
        mark++;
        Partition(A,++left,right,mark);
    }
    else if (A[left]>A[right] && mark%2==1)
    {
        swap(A[left],A[right]);
        mark++;
        Partition(A,left,--right,mark);
    }
    else
    {
        mark%2==0 ? Partition(A,left,--right,mark) : Partition(A,++left,right,mark);
        //Partition(A,++left,right,mark);
    }

}
void QuickSort(int A[],int left,int right)
{
    if (left>=right)
        return;
    else
    {
        int standard=Partition(A,left,right,0);
        QuickSort(A,left,standard-1);
        QuickSort(A,standard+1,right);
    }
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void msd_radix_sort(int A[],int begin,int end,int d)
{
    const int radix = 10;
    int count[radix], i, j;
    for (i = 0; i < radix; ++i)
    { count[i] = 0; }
    int *bucket = new int [end - begin + 1];
    for (i = begin; i <= end; ++i)
    {
        count[getdigit(A[i], d)]++;
    }
    for (i = 1; i < radix; ++i)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (i = end; i >= begin; --i)
    {
        j = getdigit(A[i], d);
        bucket[count[j] - 1] = A[i];
        --count[j];
    }
    for (i = begin, j = 0; i <= end; ++i, ++j)
    { A[i] = bucket[j]; }
    delete []bucket;
    for (i = 0; i < radix; i++)
    {
        int p1 = begin + count[i];
        int p2 = 0;                // 当前d位数值为i的桶底索引
        if (i < radix - 1)
        {
            p2 = begin + count[i + 1] - 1;//如果i=radix-1=9 count[10]不存在
        }
        else
        {
            p2 = end;
        }
        if (p1 < p2 && d > 1)
        {
            msd_radix_sort(A, p1, p2, d - 1);
        }
    }
}

int getdigit(int a, int d)
{
    char aa[12];
    //sprintf(aa,"%d",a);
    itoa(a,aa,10);
    int len=(int)_mbstrlen(aa);
    if (d>=1 and d<=len)
    {
        char c=aa[len-d];
        int b=(int)(c-'0');
        return b;
    }
    else
        return 0;
}

void lsd_radix_sort(int A[],int begin,int end,int d)
{
    const int radix=10;
    int *bucket=new int [end-begin+1];
    for (int dd=1;dd<=d;dd++)
    {
        int count[radix]={0};
        for (int i=begin;i<=end;i++)
        {
            int j=getdigit(A[i],dd);
            count[j]++;
        }
        for (int i=1;i<radix;i++)
        {
            count[i]=count[i]+count[i-1];
        }
        for (int i=end;i>=begin;i--)
        {
            int j=getdigit(A[i],dd);
            bucket[--count[j]]=A[i];
        }
        for (int i=begin;i<=end;i++)
            A[i]=bucket[i];
    }
    delete []bucket;
}
void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *space=new int[len];
    int index=0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
        space[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    while (i <= mid)
        space[index++] = A[i++];
    while (j <= right)
        space[index++] = A[j++];
    for (int k = 0; k < len; k++)
        A[left++] = space[k];
    delete[]space;
}

void MergeSortRecursion(int A[], int left, int right)
{
    if(left==right)
        return;
    else
    {
        int mid=(left+right)/2;
        MergeSortRecursion(A,left,mid);
        MergeSortRecursion(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}