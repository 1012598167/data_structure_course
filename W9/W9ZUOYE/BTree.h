//
// Created by mathskiller on 2018/12/19.
//
#include <string>
#include <queue>
#include <iostream>
using namespace std;
#ifndef W9ZUOYE_BTREE_H
#define W9ZUOYE_BTREE_H

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    string astring;
    TreeNode(){
        left=NULL;
        right=NULL;
        astring="";
    };
    TreeNode(char c)
    {
        left=NULL;
        right=NULL;
        astring=c;
    }
    TreeNode(string c)
    {
        left=NULL;
        right=NULL;
        astring=c;
    }
};

class BTree
{
public:
    TreeNode *root;
    BTree();
    ~BTree();
    bool retrieve_recursive_preorder(TreeNode *&sub_root, bool (*visit)(TreeNode* ));//retrieve for judge the type of a tree
    void post_delete_for_destruct(TreeNode*& sub_root);
    void print_pre(TreeNode *&aroot);//由于引入特殊符号 故不写retrieve //2018.12.26可以不用特殊符号了
    void print_mid(TreeNode *&aroot);//由于引入特殊符号 故不写retrieve //2018.12.26可以不用特殊符号了
    static int height(TreeNode *&aroot);
    void build_pre(TreeNode *&aroot, string &astring, int &index);
    void build_post(TreeNode *&aroot, string &astring, int &index);
    void build_BFS(string &astring);
    void build_premid(TreeNode *&aroot, string &pre, string &mid, int &index, int pstart, int pend);
    void build_midpost(TreeNode *&aroot, string &post,string &mid , int &index, int pstart, int pend);
    void find_path(string c);
    void insert(string c);
    void build_bintree(string c);//二叉查找树,a way of sort
    void delete_node(TreeNode *&aroot,string c);
    void remove(string m, TreeNode* &root);
    TreeNode* findMax(TreeNode *root)  const;
    bool is_a_complete_btree();
    static bool isab(TreeNode *aroot);
    bool is_a_bintree();//use retrieve
    bool is_AVL();
    static bool height_setle1(TreeNode*aroot);

};
#endif //W9ZUOYE_BTREE_H
