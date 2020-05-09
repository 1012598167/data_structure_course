//
// Created by mathskiller on 2018/12/27.
//

#ifndef W12TUTORIAL_GRAPH_H
#define W12TUTORIAL_GRAPH_H
const int max_size=100;

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct Node//其实是边 写错了
{
    Node(){x=0;y=0;weight=0;}
    Node(int x,int y,int w):x(x),y(y),weight(w){}
    int x;
    int y;
    int weight;
};
class Graph
{
public:
    Graph();//cin apair then use this to make adj
    void Kruskal();//最小生成树是在全连通概念下存在的
    void adj_to_apair();//in this pattern of cin,not use , use if giving adj only,that is to say,cin adj then use adj to make apair
    void DFS(void (*func)(int&));//if just traverse,adj can indeed, but DFT &BFT can be used for more like topology
    //DFS_traverse(adj[i][j],visited,func,count_visited);
    void neaten_adj();//要使dfs按字典顺序输出就要存邻接表的时候按字典顺序存
    void DFS_traverse(int &ver,bool visited[],void (*func)(int &),int & count_visited);
    static void print_int(int &a){cout<<a<<" ";flush(cout);};
    void BFS(void (*func)(int&));
    void DFS_stack(void (*func)(int &));//weight not use, the order of printing node is lexicographic
private:
    vector<Node> adj[max_size];
    vector<Node> apair;
    int visit[max_size];//for Kruskal
    int node_count;//点的个数
};


#endif //W12TUTORIAL_GRAPH_H
