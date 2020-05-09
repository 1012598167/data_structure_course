#include <iostream>
#include "Ski.h"
#include<stack>
typedef pair<int,int> pos;
using namespace std;
int main()
{
    stack<int> high;
    Ski ski;
    ski.init_Ski();
    for (int i = 1; i < ski.row+1; i++)
    {
        for (int j = 1; j < ski.col+1; j++)
        {
            pos t(i,j);
            ski.DFS(t,1);
            high.push(ski.max_s(ski.s));
        }
    }
    cout<<"DFS"<<endl;
    cout << ski.max_s(high) << endl;
    //以上为DFS
    stack<int> high1;
    Ski ski1;
    ski1.init_Ski();
    for (int i = 1; i < ski1.row+1; i++)
    {
        for (int j = 1; j < ski1.col+1; j++)
        {
            pos t1(i,j);
            high1.push(ski1.BFS(t1));
        }
    }
    cout<<"BFS"<<endl;
    cout << ski1.max_s(high1) << endl;
    return 0;
}