//
// Created by mathskiller on 2018/10/13.
//
#include <iostream>
#include "Maze.h"
#include<stack>
#include<queue>
using namespace std;
Maze::Maze()
{
    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < maxsize; j++)
        {
            status[i][j]=0;
        }
    }
    goal.first=1;goal.second=8;
    goalDFS.first=8;goalDFS.second=8;
}

Maze::~Maze()
{

}

void Maze::init_maze()
{
    size=8;
    adj_size=10;
    int amatrix[8][8]={
            {0,0,1,0,0,0,1,0},
            {0,0,1,0,0,0,1,0},
            {0,0,0,0,1,0,0,0},
            {0,1,1,1,0,0,0,0},
            {0,0,0,1,0,0,0,0},
            {0,1,0,0,0,1,0,0},
            {0,1,1,1,0,1,1,0},
            {1,1,0,0,0,0,0,0},
    };
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            status[i+1][j+1]=amatrix[i][j];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        status[0][i]=1;
        status[9][i]=1;
        status[i][0]=1;
        status[i][9]=1;
    }
}

void Maze::init_maze_DIY()
{
    int s;
    cin>>s;
    size=s;
    adj_size=s+2;
    int a=0,b=0;
    while(a!=-1 or b!=-1)
    {
        status[a][b]=1;
        cin>>a>>b;
        cout<<a<<b;
    }
    for (int i = 0; i < adj_size; i++)
    {
        status[0][i]=1;
        status[adj_size-1][i]=1;
        status[i][0]=1;
        status[i][adj_size-1]=1;
    }
}

void Maze::BFS()
{
    queue<pos> q;
    pos init(1,1);status[init.first][init.second]=2;pos goal(1,8);
    q.push(init);
    while(!q.empty())
    {
        pos tmp=q.front();
        q.pop();
        if (tmp==goal)
        {
            break;
        }
        else
        {
            if (status[tmp.first+1][tmp.second]==0)
            {
                pos tt(tmp.first+1,tmp.second);
                q.push(tt);
                past[tmp.first+1][tmp.second]=tmp;
                status[tmp.first][tmp.second]=2;
            }
            if (status[tmp.first][tmp.second+1]==0)
            {
                pos tt(tmp.first,tmp.second+1);
                q.push(tt);
                past[tmp.first][tmp.second+1]=tmp;
                status[tmp.first][tmp.second]=2;
            }
            if (status[tmp.first-1][tmp.second]==0)
            {
                pos tt(tmp.first-1,tmp.second);
                q.push(tt);
                past[tmp.first-1][tmp.second]=tmp;
                status[tmp.first][tmp.second]=2;
            }
            if (status[tmp.first][tmp.second-1]==0)
            {
                pos tt(tmp.first,tmp.second-1);
                q.push(tt);
                past[tmp.first][tmp.second-1]=tmp;
                status[tmp.first][tmp.second]=2;
            }
        }
    }

}

void Maze::PrintBFS()
{
    pos tmp=goal;pos init(1,1);
    while (tmp!=init)
    {
        status[tmp.first][tmp.second]=5;
        tmp=past[tmp.first][tmp.second];
    }
    status[init.first][init.second]=5;
    for (int i = 0; i < adj_size; i++)
    {
        for (int j = 0; j < adj_size; j++)
        {
            if (status[i][j]==2)
                status[i][j]=0;
            cout<<status[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}

stack<pos> Maze::DFS()
{
    stack<pos> s;
    int tmp_dir=0;//0=S,1=E,2=N,3=W
    pos init(1,1);
    s.push(init);
    while(s.top()!=goalDFS)
    {
        if (tmp_dir==0)//s
        {
            if(status[s.top().first+1][s.top().second]==0)//s
            {
                pos tt(s.top().first+1,s.top().second);
                s.push(tt);
            }
            else if(status[s.top().first][s.top().second+1]==0)//e
            {
                pos tt(s.top().first,s.top().second+1);
                s.push(tt);
                tmp_dir=1;
            }
            else if (status[s.top().first][s.top().second-1]==0)//w
            {
                pos tt(s.top().first,s.top().second-1);
                s.push(tt);
                tmp_dir=3;
            }
            else
            {
                status[s.top().first][s.top().second]=2;
                s.pop();
            }
        }
        else if(tmp_dir==1)//e
        {
            if(status[s.top().first+1][s.top().second]==0)//s
            {
                pos tt(s.top().first+1,s.top().second);
                s.push(tt);
                tmp_dir=0;
            }
            else if(status[s.top().first][s.top().second+1]==0)//e
            {
                pos tt(s.top().first,s.top().second+1);
                s.push(tt);

            }
            else if (status[s.top().first-1][s.top().second]==0)//n
            {
                pos tt(s.top().first-1,s.top().second);
                s.push(tt);
                tmp_dir=2;
            }
            else
            {
                status[s.top().first][s.top().second]=2;
                s.pop();
            }
        }
        else if(tmp_dir==2)//n
        {
            if(status[s.top().first][s.top().second+1]==0)//e
            {
                pos tt(s.top().first,s.top().second+1);
                s.push(tt);
                tmp_dir=1;
            }
            else if(status[s.top().first-1][s.top().second]==0)//n
            {
                pos tt(s.top().first-1,s.top().second);
                s.push(tt);

            }
            else if (status[s.top().first][s.top().second-1]==0)//w
            {
                pos tt(s.top().first,s.top().second-1);
                s.push(tt);
                tmp_dir=3;
            }
            else
            {
                status[s.top().first][s.top().second]=2;
                s.pop();
            }
        }
        else if(tmp_dir==3)//w
        {
            if(status[s.top().first+1][s.top().second]==0)//s
            {
                pos tt(s.top().first+1,s.top().second);
                s.push(tt);
                tmp_dir=0;
            }
            else if(status[s.top().first-1][s.top().second]==0)//n
            {
                pos tt(s.top().first-1,s.top().second);
                s.push(tt);
                tmp_dir=2;
            }
            else if (status[s.top().first][s.top().second-1]==0)//w
            {
                pos tt(s.top().first,s.top().second-1);
                s.push(tt);

            }
            else
            {
                status[s.top().first][s.top().second]=2;
                s.pop();
            }
        }
    }
    return s;
}

void Maze::PrintDFS(stack<pos> s)
{
    while(!s.empty())
    {
        status[s.top().first][s.top().second]=5;
        s.pop();
    }
    for (int i = 0; i < adj_size; i++)
    {
        for (int j = 0; j < adj_size; j++)
        {
            if (status[i][j]==2)
                status[i][j]=0;
            cout<<status[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}
