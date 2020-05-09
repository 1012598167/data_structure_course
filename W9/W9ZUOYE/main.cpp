#include <iostream>
#include "BTree.h"
int main()
{
    string mid("a+b*c-dse/f");
    string post("abcd-*+ef/s");
    BTree tree1;//析构用的查找树删除的循环，所以这里有特殊符号不支持析构
    int index=10;
    tree1.build_midpost(tree1.root,post,mid,index,0,11);
    tree1.print_pre(tree1.root);
    cout<<endl;


    string post2("###ca##ji####spom");
    BTree tree2;
    int index2=16;
    tree2.build_post(tree2.root,post2,index2);
    tree2.print_pre(tree2.root);
    cout<<endl;
    //string j("j");
    //tree2.delete_node(tree2.root->left->right,j);
    //tree2.print_pre(tree2.root);
    //cout<<endl;
    cout<<"is a complete tree?"<<tree2.is_a_complete_btree()<<endl;
    cout<<"is a bintree?"<<tree2.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree2.is_AVL()<<endl;
    string c("c");
    tree2.find_path(c);
    cout<<endl;
    string d("d");
    tree2.insert(d);
    tree2.print_pre(tree2.root);
    cout<<endl;
    //string d("d");
    string m("m");
    //tree2.delete_node(tree2.root,m);
    tree2.remove(m,tree2.root);
    tree2.print_pre(tree2.root);
    cout<<endl;

    string bintree("ebdfagc");
    BTree tree4;
    tree4.build_bintree(bintree);
    tree4.print_mid(tree4.root);//to sort
    cout<<endl;
    cout<<"is a bintree?"<<tree4.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree4.is_AVL()<<endl;

    string post3("541###2#3##");
    BTree tree3;
    int index3=0;
    tree3.build_pre(tree3.root,post3,index3);
    tree3.print_pre(tree3.root);
    cout<<endl;
    cout<<"is a bintree?"<<tree3.is_a_bintree()<<endl;
    cout<<"is AVL?"<<tree3.is_AVL()<<endl;
    return 0;
}