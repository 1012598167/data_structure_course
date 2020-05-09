#ifndef MAZE_H
#define MAZE_H

#include<iostream>
#include<stack>
using namespace std;

const int maxcolrow=20;

struct Pos{
    int row;
    int col;
};
class Maze
{
    public:
        Maze();
        virtual ~Maze();
        void InitMaze(int *p_matrix, int n_colrow);
        void PrintPathDFS();
        void PrintPathStack();
        void PrintMaze();

    protected:

    private:
        void DFS_(Pos cur, int step);
        bool cango_(Pos &cur);
        Pos pstart;
        Pos pend;
        int n_colrow_;
        int matrix[maxcolrow+2][maxcolrow+2];
        stack<Pos> mazestack_;
};

#endif // MAZE_H
