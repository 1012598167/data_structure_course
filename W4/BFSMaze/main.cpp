#include <iostream>

#include "Maze.h"

using namespace std;
int main()
{
    Maze maze,maze1;
    maze.init_maze();
    maze.BFS();
    maze.PrintBFS();
    cout << "above is BFS" << endl;
    maze1.init_maze();
    maze1.PrintDFS(maze1.DFS());
    cout << "above is DFS" << endl;
    return 0;
}

/*#include <iostream>
#include"Maze.h"
using namespace std;
int main()
{

    Maze maze;
    int amatrix[5][5]={
        {0,1,1,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,1,0,1,0},
        {0,0,1,0,0}
    };
    maze.InitMaze(*amatrix,5);
    maze.PrintMaze();
    cout<<"**************find the path****************"<<endl;
    maze.PrintPathDFS();
    //maze.PrintPathStack();
    return 0;
}*/
