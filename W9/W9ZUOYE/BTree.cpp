//
// Created by mathskiller on 2018/12/19.
//

#include "BTree.h"

BTree::BTree()
{
    root=NULL;
}

void BTree::print_pre(TreeNode *&aroot)
{
    if(aroot!=NULL)// and aroot->astring!="$")
    {
        cout<<aroot->astring;
        print_pre(aroot->left);
        print_pre(aroot->right);
    }
}

void BTree::print_mid(TreeNode *&aroot)
{
    if(aroot!=NULL)
    {
        print_mid(aroot->left);
        //cif (aroot->astring!="$")
            cout<<aroot->astring;
        print_mid(aroot->right);
    }
}

int BTree::height(TreeNode *&aroot)
{
    if(aroot==NULL)
        return 0;
    else
    {
        int l=height(aroot->left)+1;
        int r=height(aroot->right)+1;
        int lr=l>r?l:r;
        return lr;
    }
}

void BTree::build_pre(TreeNode *&aroot, string &astring, int &index)
{
    if(index<(int)astring.length())
    {
        if(astring[index]=='#')
            aroot=NULL;
        else
        {
            aroot=new TreeNode(astring[index]);
            build_pre(aroot->left,astring,++index);
            build_pre(aroot->right,astring,++index);
        }
    }
}

void BTree::build_post(TreeNode *&aroot, string &astring, int &index)
{
    if(index>=0)
    {
        if(astring[index]=='#')
            aroot=NULL;
        else
        {
            aroot=new TreeNode(astring[index]);
            build_post(aroot->right,astring,--index);
            build_post(aroot->left,astring,--index);
        }
    }
}

void BTree::build_BFS(string &astring)
{
    int index=0;
    queue<TreeNode*> aqueue;
    root=new TreeNode(astring[index++]);
    aqueue.push(root);
    while((int)aqueue.size())
    {
        TreeNode* node=aqueue.front();
        char achar=astring[index++];
        if(achar=='#')
            node->left=NULL;
        else
        {
            node->left=new TreeNode(achar);
            aqueue.push(node->left);
        }
        achar=astring[index++];
        if(achar=='#')
            node->right=NULL;
        else
        {
            node->right=new TreeNode(achar);
            aqueue.push(node->right);
        }
        aqueue.pop();
    }
}

bool BTree::is_a_complete_btree()
{
    queue<TreeNode*> aqueue;
    aqueue.push(root);
    while(!aqueue.empty())
    {
        TreeNode*node=aqueue.front();
        if(node==NULL)
        {
            aqueue.pop();
            if(aqueue.front()!=NULL)
                return  false;
        }
        else
        {
            aqueue.push(node->left);
            aqueue.push(node->right);
            aqueue.pop();
        }
    }
    return true;
}

void BTree::build_premid(TreeNode *&aroot, string &pre, string &mid, int &index, int pstart, int pend)
{
    int find=pstart;
    while(find<pend)
    {
        if (mid[find]==pre[index])
            break;
        find++;
    }
    if(find==pend)
        cout<<"wrong string!"<<endl;
    aroot=new TreeNode(pre[index]);
    if (find!=pstart)
        build_premid(aroot->left,pre,mid,++index,pstart,find);
    if(find+1!=pend)
        build_premid(aroot->right,pre,mid,++index,++find,pend);
}

void BTree::build_midpost(TreeNode *&aroot, string &post,string &mid, int &index, int pstart, int pend)//default index=strlen-1
{
    int find=pend-1;
    while(find>=pstart)
    {
        if (mid[find]==post[index])
            break;
        find--;
    }
    if(find==pstart-1)
        cout<<"wrong string!"<<endl;
    aroot=new TreeNode(post[index]);
    if(find+1!=pend)
        build_midpost(aroot->right,post,mid,--index,++find,pend);
    if (find!=pstart)
        build_midpost(aroot->left,post,mid,--index,pstart,--find);

}

void BTree::find_path(string c)
{
    TreeNode* aroot=root;
    while(aroot!=NULL)
    {
        cout<<aroot->astring;
        if (aroot->astring>c)
            aroot=aroot->left;
        else if(aroot->astring<c)
            aroot=aroot->right;
        else
            return;
    }
    cout<<endl;
    cout<<"to the bottom,not found"<<endl;
}

void BTree::insert(string c)
{
    if (root==NULL)
        root=new TreeNode(c);
    else
    {
        TreeNode* aroot=root;
        while(1)
        {
            if (aroot->astring>c)
            {
                if(aroot->left==NULL)
                {
                    aroot->left=new TreeNode(c);
                    return;
                }
                aroot=aroot->left;
            }
            else if(aroot->astring<c)
            {
                if(aroot->right==NULL)
                {
                    aroot->right=new TreeNode(c);
                    return;
                }
                aroot=aroot->right;
            }
            else
            {
                cout<<"fail to insert"<<endl;
                return;
            }
        }
    }
}

void BTree::build_bintree(string c)
{
    for (int i=0;i<(int)c.length();i++)
    {
        string achar(1,c[i]);//string a(1,char) 将char转为string
        insert(achar);
    }
}

void BTree::delete_node(TreeNode *&aroot,string c)
{
    if(aroot->left==NULL and aroot->right==NULL)
    {
        delete aroot;
        aroot=NULL;
        //aroot->astring="$";
        return;
    }
    while(aroot!=NULL)
    {
        if(aroot->left!=NULL and aroot->left->astring==c and aroot->left->left==NULL and aroot->left->right==NULL)
        {
            delete aroot->left;
            aroot->left=NULL;
            return;
        }//删除节点为叶子的情况
        if(aroot->right!=NULL and aroot->right->astring==c and aroot->right->left==NULL and aroot->right->right==NULL)
        {
            delete aroot->right;
            aroot->right=NULL;
            return;
        }//删除节点为叶子的情况
        if (aroot->astring>c)
            aroot=aroot->left;
        else if(aroot->astring<c)
            aroot=aroot->right;
        else
            break;
    }
    if (aroot==NULL)
    {
        cout<<"to the bottom,not found"<<endl;
        return;
    }
    //above is find
/*    if(aroot->left==NULL and aroot->right==NULL)
    {
       aroot->astring="$";
    }*/
    else if (aroot->left!=NULL and aroot->right==NULL)
    {
        aroot->astring=aroot->left->astring;
        aroot->right=aroot->left->right;
        aroot->left=aroot->left->left;
    }
    else if (aroot->right!=NULL and aroot->left==NULL)
    {
        aroot->astring=aroot->right->astring;
        aroot->left=aroot->right->left;
        aroot->right=aroot->right->right;
    }
    else
    {
        TreeNode* find_left_most_right=aroot->left;
        while(find_left_most_right->right!=NULL)
            find_left_most_right=find_left_most_right->right;
        aroot->astring=find_left_most_right->astring;
        delete_node(find_left_most_right,find_left_most_right->astring);
    }
}//更为合适的两种写法 1调和删分两个函数 调的函数递归找到后的if调用删   //调=找要删的点
//2 就写一个删函数 删函数递归部分写调 递归完了后if写删
//总之不能把调的函数的结果返回作为删的参数 这样地址不对

void BTree::remove(string m, TreeNode* &root)//这是第二种做法
{
    if ( root == NULL )
        return;  //没找到对应的项，什么也不做；
    if ( m < root->astring)
        remove(m, root->left);
    else if (root->astring < m)
        remove(m, root->right);
    else if (root->left != NULL && root->right != NULL) // 有两个孩子
    {
        root->astring = findMax(root->left)->astring; //找到左子树的最大节点，替换该节点的值
        remove(root->astring, root->left); //再递归删除那个节点
    }
    else //只有一个孩子，或为叶子节点
    {
        TreeNode*oldNode = root;
        root = (root->left != NULL) ?  root->left : root->right; //把该节点换成非空子节点
        delete oldNode; //删除旧节点
        oldNode=NULL;
    }
}
TreeNode * BTree::findMax(TreeNode *root)  const
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    return findMax( root->right);
}

BTree::~BTree()
{
    /*while(root!=NULL)
        remove(root->astring,root);*/
    post_delete_for_destruct(root);
}

bool BTree::retrieve_recursive_preorder(TreeNode *&sub_root, bool (*visit)(TreeNode *))
{
    if (sub_root != NULL) {
        if (!(*visit)(sub_root))
            return true;//是为了return false 但是因为无return返回false故在①这翻转结果
        retrieve_recursive_preorder(sub_root->left, visit);
        retrieve_recursive_preorder(sub_root->right, visit);
    }
}//无return则return false

bool BTree::is_a_bintree()
{
    return !retrieve_recursive_preorder(root,isab);//①
}

bool BTree::isab(TreeNode *aroot)
{
    if(aroot->left!=NULL)
        if(aroot->astring<=aroot->left->astring)
            return false;
    if(aroot->right!=NULL)
        if(aroot->astring>=aroot->right->astring)
            return false;
    return true;
}

bool BTree::is_AVL()
{
    return !retrieve_recursive_preorder(root,height_setle1);
}

bool BTree::height_setle1(TreeNode*aroot)
{
    int a=height(aroot->left)-height(aroot->right);
    int b=a>=0?a:-a;
    return b<=1;
}

void BTree::post_delete_for_destruct(TreeNode *&sub_root)
{
    if (sub_root != NULL) {
        post_delete_for_destruct(sub_root->left);
        post_delete_for_destruct(sub_root->right);
        delete sub_root;
        sub_root=NULL;
    }
}
