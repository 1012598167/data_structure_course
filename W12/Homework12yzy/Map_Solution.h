#ifndef HOMEWORK12_MAP_SOLUTION_H
#define HOMEWORK12_MAP_SOLUTION_H
#include <vector>
#define  SIZE 6
using  namespace std;
struct Node{
    int x,y;
    int weight;
//    Node(int a,int b){
//        this->sign=a;
//        this->weight=b;
//    };
};

class Map_Solution {
public:
    Map_Solution();
    ~Map_Solution();
    void Create();
    void Kruskal();
    void  Print();

private:
    int count;
    vector<Node> adj[SIZE];
    vector<Node> all;
};


#endif //HOMEWORK12_MAP_SOLUTION_H
