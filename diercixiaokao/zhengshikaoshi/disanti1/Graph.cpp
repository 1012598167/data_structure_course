//
// Created by mathskiller on 2018/12/29.
//

#include "Graph.h"
#include "Graph.h"
#include <algorithm>



int Cmp_y(Node a,Node b)//排序函数
{
    return a.y.length()<=b.y.length();
}
Graph::Graph()
{
    node_count=0;
    string xx[10];string yy[10];
    xx[5]="Hailey";yy[5]="Bella";
    xx[0]="Emma";yy[0]="May";
    xx[1]="Emma";yy[1]="Edith";
    xx[2]="Emma";yy[2]="Joyce";
    xx[3]="Joyce";yy[3]="Jessie";
    xx[4]="Jessie";yy[4]="Hailey";
    xx[6]="Hailey";yy[6]="Gloria";
    xx[7]="Edith";yy[7]="Gloria";
    xx[8]="Emma";yy[8]="May";
    for(int i=0;i<9;i++)
        apair.push_back(Node(xx[i],yy[i]));
    vector<Node> a0;
    a0.push_back(Node(xx[0],yy[1]));
    a0.push_back(Node(xx[1],yy[2]));
    a0.push_back(Node(xx[2],yy[0]));
    adj.push_back(pair<string,vector<Node>>(xx[0],a0));

    vector<Node> a1;
    a1.push_back(Node(xx[3],yy[3]));
    a1.push_back(Node(xx[3],yy[4]));
    a1.push_back(Node(xx[3],xx[0]));
    adj.push_back(pair<string,vector<Node>>(xx[3],a1));

    vector<Node> a2;
    a2.push_back(Node(xx[4],yy[4]));
    a2.push_back(Node(xx[4],xx[3]));
    adj.push_back(pair<string,vector<Node>>(xx[4],a2));

    vector<Node> a3;
    a3.push_back(Node(xx[5],xx[4]));
    a3.push_back(Node(xx[5],yy[6]));
    a3.push_back(Node(xx[5],yy[5]));
    a3.push_back(Node(xx[5],yy[2]));
    adj.push_back(pair<string,vector<Node>>(xx[5],a3));

    vector<Node> a4;
    a4.push_back(Node(yy[5],xx[5]));
    adj.push_back(pair<string,vector<Node>>(yy[5],a4));

    vector<Node> a5;
    a5.push_back(Node(yy[7],yy[4]));
    a5.push_back(Node(yy[7],yy[1]));
    adj.push_back(pair<string,vector<Node>>(xx[5],a5));

    vector<Node> a6;
    a6.push_back(Node(yy[1],yy[7]));
    a6.push_back(Node(yy[1],xx[0]));
    adj.push_back(pair<string,vector<Node>>(yy[1],a6));

    vector<Node> a7;
    a7.push_back(Node(yy[8],xx[0]));
    adj.push_back(pair<string,vector<Node>>(yy[8],a7));

    node_count=8;
}

void Graph::DFS_stack(void (*func)(string &))
{
/*    neaten_adj();
    bool visited[max_size]={false};
    int count_visited=0;
    stack<int> astack;
    for (int i=0;i<max_size;i++)
    {
        if(visit[i]!=-1 and !visited[i])
        {
            astack.push(i);
            visited[i]=true;
            count_visited++;
            func(i);
            while(!astack.empty())
            {
                int top=astack.top();
                for (int j=0;j<adj[top].size();j++)
                {
                    if(count_visited==node_count)
                        return;
                    int aa=adj[top][j].y;
                    if(!visited[aa])
                    {
                        astack.push(aa);
                        visited[aa]=true;
                        count_visited++;
                        func(aa);
                        j=0;
                        top=aa;
                    }
                }
                astack.pop();
            }
        }
    }*/
}

void Graph::DFS(void (*func)(string &))
{
/*    neaten_adj();
    bool visited[max_size]={false};
    int count_visited=0;
    for (int i=0;i<max_size;i++)// ①
    {
        if(visit[i]!=-1)
        {
            func(i);
            visited[i]=true;
            count_visited++;
            if(count_visited==node_count)
                return;
            for (int j=0;j<adj[i].size();j++)//②
   //①and② traverse all adj,it seems useless,its just for preventing 有孤立的或者说不连通的
            {
                DFS_traverse(adj[i][j].y,visited,func,count_visited);
                if(count_visited==node_count)
                    return;
            }
        }
    }*/
}

void Graph::DFS_traverse(int &ver, bool *visited, void (*func)(string &),int & count_visited)
{
/*    if(count_visited==node_count)
        return;
    if (visited[ver])
        return;
    visited[ver]= true;
    count_visited++;
    (*func)(ver);
    for(int i=0;i<adj[ver].size();i++)
    {
        int now=adj[ver][i].y;//all now adjacent to ver
        if (!visited[now])
            DFS_traverse(now,visited,func,count_visited);
    }*/
}

void Graph::neaten_adj()
{
/*    for (int i=0;i<max_size;i++)// ①
    {
        if (visit[i] != -1)
        {
            sort(adj[i].begin(),adj[i].end(),Cmp_y);
        }
    }*/
}

void Graph::BFS(void (*func)(string&))
{
/*    queue<int> q;
    int count_visited=0;
    bool visited[max_size]={false};
    for (int i=0;i<max_size;i++)// ①
    {
        if(visit[i]!=-1)
        {
            q.push(i);
            func(i);
            visited[i]=true;
            count_visited++;
            if(count_visited==node_count)
                return;
            while(!q.empty())
            {
                int f=q.front();
                for (int j=0;j<adj[f].size();j++)
                {
                    int target=adj[f][j].y;
                    if(!visited[target])
                    {
                        visited[target]=true;
                        count_visited++;
                        //func(target);
                        q.push(target);
                    }
                }
                if(count_visited==node_count)
                    return;
                q.pop();
            }
        }
    }*/

}

void Graph::print()
{
    for(int i=0;i<adj.size();i++)
    {
        cout<<adj[i].first<<"   ";
        for(int j=0;j<adj[i].second.size();j++)
        {
            cout<<(adj[i].second)[j].y<<" ";
        }

        cout<<endl;
    }
}
