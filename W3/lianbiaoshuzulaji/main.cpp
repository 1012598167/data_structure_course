#include <iostream>
using namespace std;
struct Node {
    int entry;
    Node *next;
};
int main()
{
    int n;

    cin>>n;
    int tempn=n;
    Node * head;
    Node *tmp=new Node;
    head=tmp;
    while (tempn--)
    {
        tmp->next=new Node;
        tmp->next->entry=1;
        tmp=tmp->next;
    }
    tmp->next=NULL;
    Node* last=tmp;
    tmp=head;
    while (tmp->next!=NULL)
    {
        cout<<tmp->next->entry<<endl;
        tmp=tmp->next;
    }
    return 0;
}