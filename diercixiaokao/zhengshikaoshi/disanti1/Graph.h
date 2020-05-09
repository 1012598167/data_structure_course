//
// Created by mathskiller on 2018/12/29.
//

#ifndef DIERTI_GRAPH_H
#define DIERTI_GRAPH_H


const int max_size=100;

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
struct Node//其实是边 写错了
{
    Node(string x,string y):x(x),y(y){}
    string x;
    string y;
};
class Graph
{
public:
    Graph();//cin apair then use this to make adj
    void DFS(void (*func)(string &));//if just traverse,adj can indeed, but DFT &BFT can be used for more like topology
    //DFS_traverse(adj[i][j],visited,func,count_visited);
    void neaten_adj();//要使dfs按字典顺序输出就要存邻接表的时候按字典顺序存
    void DFS_traverse(int &ver,bool visited[],void (*func)(string &),int & count_visited);
    static void print_int(string &a){cout<<a<<" ";flush(cout);};
    void BFS(void (*func)(string&));
    void DFS_stack(void (*func)(string &));//weight not use, the order of printing node is lexicographic
    void print();
private:
    vector<pair<string,vector<Node>>> adj;
    vector<Node> apair;
    int node_count;//点的个数
};


#endif //DIERTI_GRAPH_H
