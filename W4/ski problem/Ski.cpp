//
// Created by mathskiller on 2018/10/14.
//

#include "Ski.h"
using namespace std;
typedef pair<int,int> pos;

Ski::Ski()
{

}

void Ski::init_Ski()
{
    int init[5][5]={1,2,3,4,5,16,17,18,19,6,15,24,25,20,7,14,23,22,21,8,13,12,11,10,9};
    row=5;col=5;adj_col=7;adj_row=7;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            status[i+1][j+1]=init[i][j];
        }
    }
    for (int i = 0; i < 7; i++)
    {
        status[0][i]=101;
        status[6][i]=101;
        status[i][0]=101;
        status[i][6]=101;
    }
}

pos Ski::find_number(int start)
{
    for (int i = 0; i < adj_row; i++)
    {
        for (int j = 0; j < adj_col; j++)
        {
            if (status[i][j]==start)
            {
                pos a(i,j);
                return a;
            }
        }
    }
}

void Ski::DFS(pos past, int length)
{
    if(status[past.first][past.second-1]<status[past.first][past.second])//left
    {
        pos temp(past.first,past.second-1);
        DFS(temp,length+1);
    }
    if (status[past.first][past.second+1]<status[past.first][past.second])//right
    {
        pos temp(past.first,past.second+1);
        DFS(temp,length+1);
    }
    if(status[past.first-1][past.second]<status[past.first][past.second])//above
    {
        pos temp(past.first-1,past.second);
        DFS(temp,length+1);
    }
    if(status[past.first+1][past.second]<status[past.first][past.second])//below
    {
        pos temp(past.first+1,past.second);
        DFS(temp,length+1);
    }
    if (not(status[past.first][past.second-1]<status[past.first][past.second] or status[past.first][past.second+1]<status[past.first][past.second] or status[past.first-1][past.second]<status[past.first][past.second] or status[past.first+1][past.second]<status[past.first][past.second]))
    {
        s.push(length);
        return;
    }
}

int Ski::max_s(stack<int> s)
{
    int a=0,b;
    while (!s.empty())
    {
        b=s.top();
        if (b>a)
            a=b;
        s.pop();
    }
    return a;
}

int Ski::BFS(pos top_one)
{
    for (int i = 1; i < row + 1; i++)
    {
        for (int j = 1; j < col + 1; j++)
        {
            bansui[i][j]=0;
        }
    }
    while(!q.empty())
    {
        q.pop();
    }
    //the direction of the movement
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//0:s 1:e 2:n 3:w
    q.push(top_one);
    bansui[top_one.first][top_one.second]=1;
    pos temp;
    pos result;
    while (!q.empty())
    {


        for (int z = 0; z < 4; z++)
        {
            temp=q.front();
            temp.first=temp.first+dir[z][0];
            temp.second=temp.second+dir[z][1];
            if (status[temp.first][temp.second]<status[q.front().first][q.front().second])
            {
                q.push(temp);
                bansui[temp.first][temp.second]=bansui[q.front().first][q.front().second]+1;
            }

        }

        q.pop();
        if(q.size()==1)
            result=q.front();
    }

    return bansui[result.first][result.second];
}
