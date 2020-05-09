#include <iostream>
using namespace std;
typedef int Node_entry;
struct Node {
    Node_entry entry;
    Node *next;
    // constructors 构造函数
    Node( );
    Node(Node_entry item, Node *add_on = NULL);

};
int main()
{
    int n,m,xh=1;

    cin>>n>>m;
    int tempn=n;
    Node * head=new Node;
    Node *tmp=new Node;
//    head=tmp;
    while (tempn--)
    {
        tmp->next=new Node(xh++);
        if(tempn==n-1)
            head=tmp->next;
        tmp=tmp->next;

    }
    tmp->next=head;
    xh=1;
    tmp=head;

    while (tmp->next->entry!=tmp->next->next->entry)
    {
        if(++xh==m)
        {
            Node *tmptmp=new Node;
            tmptmp->next=tmp->next->next;
            delete tmp->next;
            tmp->next=NULL;
            tmp->next=tmptmp->next;
            delete tmptmp;
            tmptmp=NULL;
            xh =1;
        }


        tmp=tmp->next;
    }
    cout<<tmp->next->entry<<endl;
/*    int xh=1;
    int shengyu=n;
    while(shengyu>1)
    {
        if (r->entry==0)
        {
            r=r->next;
            continue;
        }
        if (xh%m==0)
        {
            r->entry=0;
*//*            k=r->next;
            r->next=r->next->next;
            delete k;
            k=NULL;*//*
            shengyu--;
        }
        xh++;
        r=r->next;
    }


    cout<<r->entry<<endl;*/

    return 0;
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
