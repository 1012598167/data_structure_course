#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Map_Solution.h"
#define MAX 100
using namespace std;
int fa[MAX];
int sum=0;

void Make_set(int x)//初始化节点
{
    fa[x]=x;
}

int Cmp(Node a,Node b)//排序函数
{
    if(a.weight!=b.weight)
        return a.weight<b.weight;
    else
    {
        return a.x<b.x;
    }
}

int Find(int x)//查找父节点
{
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}

void Union_set(int x,int y,int w)//合并节点
{
    fa[fa[x]]=fa[y];
    cout<<x<<"->"<<y<<"   "<<"Length:"<<w<<endl;
    sum+=w;//总权值加上w
}

Map_Solution::Map_Solution() {
    count=SIZE;
}

Map_Solution::~Map_Solution() {

}

void Map_Solution::Create() {
    Node a;
    a={0,1,6};
    adj[0].push_back(a);
    a={0,3,4};
    adj[0].push_back(a);
    a={1,0,6};
    adj[1].push_back(a);
    a={1,2,10};
    adj[1].push_back(a);
    a={1,3,7};
    adj[1].push_back(a);
    a={1,4,7};
    adj[1].push_back(a);
    a={2,1,10};
    adj[2].push_back(a);
    a={2,3,8};
    adj[2].push_back(a);
    a={2,4,5};
    adj[2].push_back(a);
    a={2,5,6};
    adj[2].push_back(a);
    a={3,0,4};
    adj[3].push_back(a);
    a={3,1,7};
    adj[3].push_back(a);
    a={3,2,8};
    adj[3].push_back(a);
    a={3,4,12};
    adj[3].push_back(a);
    a={4,1,7};
    adj[4].push_back(a);
    a={4,2,5};
    adj[4].push_back(a);
    a={4,3,12};
    adj[4].push_back(a);
    a={4,5,7};
    adj[4].push_back(a);
    a={5,2,6};
    adj[5].push_back(a);
    a={5,4,7};
    adj[5].push_back(a);
}

void Map_Solution::Print() {
    int i,j;
    for(i=0;i<count;i++){
        cout<<i<<endl;
        for(j=0;j<adj[i].size();j++){
            cout<<"sign:"<<adj[i][j].x<<","<<adj[i][j].y<<endl;
            cout<<"weight:"<<adj[i][j].weight<<endl;
        }
        cout<<endl;
    }
}

void Map_Solution::Kruskal() {
    int i,j,k;
    int s=1;
    for(i=0;i<count;i++){
        for(j=0;j<adj[i].size();j++){
            for(k=0;k<all.size();k++){
                if(all[k].x==adj[i][j].y && all[k].y==adj[i][j].x){
                    s=-1;
                }
            }
            if(s==1){
                all.push_back(adj[i][j]);
            }
            s=1;
        }
    }
    for(k=0;k<all.size();k++){
//        cout<<"sign:"<<all[k].x<<","<<all[k].y<<endl;
//        cout<<"weight:"<<all[k].weight<<endl;
        cout<<all[k].x<<" "<<all[k].y<<" "<<all[k].weight<<endl;
    }
    int m=(int)all.size();
    int n=count;
    int x,y,weight;
    for(k=0;k<all.size();k++){
        Make_set(all[k].x);
        Make_set(all[k].y);
    }
    k=1;
    sort(all.begin(),all.end(),Cmp);
    for(i=0;i<m;i++){
        x=Find(all[i].x);
        y=Find(all[i].y);
        weight=all[i].weight;
        if(x!=y && k<n) {
            Union_set(all[i].x,all[i].y,weight);
            k++;
        }
        if(k==n){
            break;
        }
    }
    cout<<"Total length:"<<sum<<endl;
}



