#include <iostream>
#include "list.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<string> split(string &str, const string &pattern)//pattern 以该字符分隔
{
    unsigned int pos;
    vector<string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    unsigned int i;
    for(i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

int main()
{
    //getchar();
    Record record1[5];Record record2[5];
    string pattern(" ");
    string str;
    getline(cin,str);
    vector<string>result=split(str,pattern);
    vector<int> a;
    for(int i=0;i<result.size();i++)
        a.push_back(atoi(result[i].c_str()));
    for(int i=0;i<a.size();i++)
        record1[i]=a[i];
    getline(cin,str);
    vector<string>result2=split(str,pattern);
    vector<int> a2;
    for(int i=0;i<result2.size();i++)
        a2.push_back(atoi(result2[i].c_str()));
    for(int i=0;i<a2.size();i++)
        record2[i]=a2[i];
    list alist1;
    for (int i=0;i<5;i++)
    {
        Node* node=new Node(record1[i]);
        alist1.append(node);
    }
    alist1.merge_sort();
    list alist2;
    for (int i=0;i<5;i++)
    {
        Node* node=new Node(record2[i]);
        alist2.append(node);
    }
    alist2.merge_sort();
    //alist2.print();
    list alist3;
    Node* aaa=alist3.merge(alist1.get_head(),alist2.get_head());
    Node* r=aaa;
    while(r!=NULL)
    {
        cout<<r->entry.the_record()<<" ";
        r=r->next;
    }
    return 0;
}