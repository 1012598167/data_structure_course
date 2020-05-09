//
// Created by mathskiller on 2018/12/24.
//

#include "heapsort.h"

bool operator >(const Node&a,const Node &b)
{
    if(a.x_ != b.x_)
        return a.x_>b.x_;
    else
        return a.y_>b.y_;
}

ostream & operator << (ostream &out, Node &a)
{
    out<<"<"<<a.x_<<","<<a.y_<<">";flush(out);
    return out;
}

void swap(heap_array &a,heap_array &b)
{
    heap_array temp;
    temp=a;
    a=b;
    b=temp;
}

Node::Node()
{
    x_=0;
    y_=0;
}

Node::Node(int a, int b)
{
    x_=a;
    y_=b;
}

heap_array heapsort::Heap_Extract_Max(heap_array *&A)
{
    heap_array max=A[1];
    A[1]=A[n];
    n--;
    Heapify(A,1,n);
    return max;
}

void heapsort::Heapify(heap_array *&A, int i,int num)//num=n in normal section num=k in topk
{
    int l=2*i;int r=2*i+1;
    int largest;
    if(l<=num and A[l]>A[i])
        largest=l;
    else
        largest=i;
    if(r<=num and A[r]>A[largest])
        largest=r;
    if (largest!=i)
    {
        swap(A[i],A[largest]);
        Heapify(A,largest,num);
    }
}

void heapsort::Build_Heap(heap_array *array, int size)
{
    for(int i=0;i<size;i++)
        node[i+1]=array[i];
    n=size;
    for (int i = n/2; i >= 1; i--)
    {
        Heapify(node,i,n);
    }
}

void heapsort::Heapsort(heap_array *&A,int size)
{
    Build_Heap(A,size);
    for(int i=n;i>=2;i--)
    {
        cout<<node[1];
        swap(node[1],node[i]);
        n--;
        Heapify(node,1,n);
    }
    cout<<node[1]<<endl;
}

void heapsort::Heap_insert(heap_array key)
{
    n++;
    node[n]=key;
    int i=n;
    while(i>1 and key>node[i/2])
    {
        swap(node[i],node[i/2]);
        i/=2;
    }
}

int heapsort::get_size()
{
    return n;
}

heapsort::heapsort(int c)
{
    n=0;
    node=new heap_array[max_size];
    k=c;
}

heapsort::~heapsort()
{
    delete []node;
}

void heapsort::add(heap_array a)
{
    node[++n]=a;
    if(n==k)
    {
        for (int i = n/2; i >= 1; i--)
        {
            Heapify(node,i,k);
        }
    }
    if(n>k)
    {
        if(node[1]>node[n])
        {
            swap(node[1],node[n]);
            Heapify(node,1,k);
        }
    }
}

void heapsort::get_topk()
{
    if(n<k)
    {
        for (int i = 1; i <= n; i++)
            cout << node[i];
    }
    else
    {
        for (int i = 1; i <= k; i++)
            cout << node[i];
    }
}
