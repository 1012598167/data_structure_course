//
// Created by mathskiller on 2018/10/13.
//

#ifndef BFSMAZE_MAZE_H
#define BFSMAZE_MAZE_H
const int maxsize=30;
#include<stack>
#include<queue>
using namespace std;
typedef pair<int,int> pos;

class Maze
{
public:
    Maze();
    ~Maze();
    void init_maze();
    void init_maze_DIY();
    void BFS();
    void PrintBFS();
    stack<pos> DFS();
    void PrintDFS(stack<pos> s);
private:
    int size;
    int adj_size;
    int status[maxsize][maxsize];
    //status[a][b] a,b为pos 0/1/2=空/墙/被占用
    //
    pos past[maxsize][maxsize];
    pos goal;
    pos goalDFS;
};


#endif //BFSMAZE_MAZE_H
