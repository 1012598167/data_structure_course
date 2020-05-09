#include "Maze.h"

Maze::Maze()
{
    //ctor

}

Maze::~Maze()
{
    //dtor
}

bool Maze::cango_(Pos &cur){
    return matrix[cur.row][cur.col]!=0? false:true;
}

void Maze::InitMaze(int *p_matrix, int n_colrow){
    for(int z=0;z<=n_colrow+1;z++){
        matrix[0][z]=1;
        matrix[n_colrow+1][z]=1;
        matrix[z][0]=1;
        matrix[z][n_colrow+1]=1;
    }
    for(int z=1;z<=n_colrow;z++){
        for(int zz=1;zz<=n_colrow;zz++){
                matrix[z][zz]=p_matrix[(z-1)*n_colrow+zz-1];
        }
    }
    pstart.row=1;
    pstart.col=1;
    pend.row=n_colrow;
    pend.col=n_colrow;
    n_colrow_=n_colrow;

}
void Maze::DFS_(Pos cur, int step){
     if(cur.row==pend.row && cur.col==pend.col){
        PrintMaze();
        return;
     }
     int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
     Pos next;
     for(int z=0;z<4;z++){
        next.row=cur.row+dir[z][0];
        next.col=cur.col+dir[z][1];
        // Try next pos
        if(cango_(next)){
            matrix[next.row][next.col]=step+1;
            DFS_(next,step+1);
            //step--;
            matrix[next.row][next.col]=0;
        }
     }
}
void Maze::PrintPathDFS(){
    matrix[pstart.row][pstart.col]=2;
    DFS_(pstart,2);
}



void Maze::PrintPathStack(){
    mazestack_.push(pstart);
    matrix[pstart.row][pstart.col]=5;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    while(!mazestack_.empty()){
        Pos cur=mazestack_.top();
        if(cur.col==pend.col && cur.row==pend.row){
                PrintMaze();
                return;
        }
        Pos next;
        bool canexpand=false;
        for(int z=0;z<4;z++){
            next.row=cur.row+dir[z][0];
            next.col=cur.col+dir[z][1];
            if(cango_(next)){
                canexpand=true;
                matrix[next.row][next.col]=5;
                mazestack_.push(next);
                break;
            }
        }
        if(!canexpand){
            matrix[cur.row][cur.col]=9;
            mazestack_.pop();
        }
    }
}

void Maze::PrintMaze(){
    for(int z=1;z<=n_colrow_;z++){
        for(int zz=1;zz<=n_colrow_;zz++)
            cout<<matrix[z][zz]<<" ";
        cout<<endl;
    }
    cout<<"-----------------------------------"<<endl;
}
