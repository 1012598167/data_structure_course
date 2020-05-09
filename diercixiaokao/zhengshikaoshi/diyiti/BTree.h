//
// Created by mathskiller on 2018/12/29.
//



#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int aint;
    TreeNode(){
        left=NULL;
        right=NULL;
        aint=0;
    };
    TreeNode(int i)
    {
        left=NULL;
        right=NULL;
        aint=i;
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
    void build_pre(TreeNode *&aroot, vector<int> v, int &index);//index=0
    void build_post(TreeNode *&aroot, vector<int> v, int &index);//index=v.size()-1
    void build_BFS(vector<int> v);
    void build_premid(TreeNode *&aroot, vector<int> &pre, vector<int> &mid, int &index, int pstart, int pend);//index=0 pstart=0 pend=v.size()
    void build_midpost(TreeNode *&aroot, vector<int> &post,vector<int> &mid , int &index, int pstart, int pend);//index=0 pstart=v.size()-1 pend=v.size()
    int find_path(int c);
    void insert(int c);//for bintree
    void build_bintree(vector<int> c);//二叉查找树,a way of sort
    void delete_node(TreeNode *&aroot,int c);
    void remove(int m, TreeNode* &root);
    TreeNode* findMax(TreeNode *root)  const;
    bool is_a_complete_btree();
    static bool isab(TreeNode *aroot);
    bool is_a_bintree();//use retrieve
    bool is_AVL();
    static bool height_setle1(TreeNode*aroot);
    int max_road();
    void kong(TreeNode *&aroot);
    void rrr(TreeNode *&aroot);
    void dealwith();
    vector<int> aaaa;
    stack<int> aa;
    vector<stack<int>> manystack;
};




