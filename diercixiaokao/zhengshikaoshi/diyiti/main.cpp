#include "BTree.h"
#include <fstream>



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
    string pattern(",");
    string str;
    getline(cin,str);
    vector<string>result=split(str,pattern);
    vector<int> a;
    string jing("#");
    for(int i=0;i<result.size();i++)
    {
        if(result[i]==jing)
            a.push_back(-1);
        else
            a.push_back(atoi(result[i].c_str()));
    }
    BTree atree;
    int index1=0;
    atree.build_pre(atree.root,a,index1);
    atree.print_mid(atree.root);
    cout<<endl;
    cout<<atree.max_road()<<endl;
    /*for(int i=0;i<a.size();i++)
        cout<<a[i]<<endl;*/
/*
    int apost2[]={-1,-1,-1,3,1,-1,-1,10,9,-1,-1,-1,-1,19,16,15,13};
    vector<int> post2(apost2,apost2+17);
    BTree tree2;
    int index2=16;
    tree2.build_post(tree2.root,post2,index2);
    tree2.print_pre(tree2.root);
    cout<<endl;*/
    return 0;
}
/*
#include "BTree.h"
#include <iostream>
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
*/
/*    string pattern(" ");
    string str;
    getline(cin,str);
    vector<string>result=split(str,pattern);
    vector<int> v;
    for(int i=0;i<result.size();i++)
        v.push_back(atoi(result[i].c_str()));
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;*//*




    int amid[]={1,101,2,103,3,102,4,9,5,104,6};
    int apost[]={1,2,3,4,102,103,101,5,6,104,9};
    vector<int> mid(amid,amid+11);
    vector<int> post(apost,apost+11);
    BTree tree1;//析构用的查找树删除的循环，所以这里有特殊符号不支持析构
    int index=10;
    tree1.build_midpost(tree1.root,post,mid,index,0,11);
    tree1.print_pre(tree1.root);
    cout<<endl;

    int apost2[]={-1,-1,-1,3,1,-1,-1,10,9,-1,-1,-1,-1,19,16,15,13};
    vector<int> post2(apost2,apost2+17);
    BTree tree2;
    int index2=16;
    tree2.build_post(tree2.root,post2,index2);
    tree2.print_pre(tree2.root);
    cout<<endl;
    tree2.delete_node(tree2.root->left->right,10);
    tree2.print_pre(tree2.root);
    cout<<endl;
    cout<<"is a complete tree?"<<tree2.is_a_complete_btree()<<endl;
    cout<<"is a bintree?"<<tree2.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree2.is_AVL()<<endl;
    tree2.find_path(3);
    cout<<endl;
    tree2.insert(4);
    tree2.print_pre(tree2.root);
    cout<<endl;
    //string d("d");
    //string m("m");
    //tree2.delete_node(tree2.root,m);
    tree2.remove(13,tree2.root);
    tree2.print_pre(tree2.root);
    cout<<endl;

    int abintree[]={5,2,4,6,1,7,3};
    vector<int> bintree(abintree,abintree+7);
    //string bintree("ebdfagc");
    BTree tree4;
    tree4.build_bintree(bintree);
    tree4.print_mid(tree4.root);//to sort
    cout<<endl;
    cout<<"is a bintree?"<<tree4.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree4.is_AVL()<<endl;

*/
/*    string post3("541###2#3##");
    BTree tree3;
    int index3=0;
    tree3.build_pre(tree3.root,post3,index3);
    tree3.print_pre(tree3.root);
    cout<<endl;
    cout<<"is a bintree?"<<tree3.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree3.is_AVL()<<endl;*//*

    return 0;
}*/
