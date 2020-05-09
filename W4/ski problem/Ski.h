//
// Created by mathskiller on 2018/10/14.
//
const int maxsize=10;
#ifndef SKI_PROBLEM_SKI_H
#define SKI_PROBLEM_SKI_H
#include<stack>
#include<queue>
using namespace std;
typedef pair<int,int> pos;

class Ski
{
public:
    Ski();
    void init_Ski();
    pos find_number(int start);
    void DFS(pos past,int length);
    int BFS(pos top_one);
    int max_s(stack<int> s);
    int row;
    int col;
    int adj_row;
    int adj_col;
    stack<int> s;
    queue<pos> q;
private:
    int start;

    int status[maxsize][maxsize];
    int bansui[maxsize][maxsize];

};


#endif //SKI_PROBLEM_SKI_H
