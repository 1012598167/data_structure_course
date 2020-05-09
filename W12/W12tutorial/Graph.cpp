//
// Created by mathskiller on 2018/12/27.
//

#include "Graph.h"
#include <algorithm>

int Cmp_weight(Node a,Node b)//排序函数
{
    if(a.weight!=b.weight)
        return a.weight<b.weight;
    else
    {
        return a.x<b.x;
    }
}
int Cmp_y(Node a,Node b)//排序函数
{
    return a.y<=b.y;
}
Graph::Graph()
{
    for(int i=0;i<max_size;i++)
        visit[i]=-1;//initialize
    node_count=0;
    int x=0,y=0,w=0;
    while(cin>>x>>y>>w and x+1 and y+1 and w+1)
    {
        if(x<=y)
        {
            Node node(x,y,w);
            Node node2(y,x,w);
            apair.push_back(node);
            adj[x].push_back(node);
            adj[y].push_back(node2);

        }
        else
        {
            Node node(y,x,w);
            Node node2(x,y,w);
            apair.push_back(node);
            adj[y].push_back(node);
            adj[x].push_back(node2);
        }
        if(visit[x]==-1) {node_count++; visit[x]=x;}
        if(visit[y]==-1) {node_count++; visit[y]=y;}
    }
}

void Graph::Kruskal()
{
    sort(apair.begin(),apair.end(),Cmp_weight);
    int count_cout_pair=0;
    for(int i=0;i<apair.size();i++)
    {
        Node now=apair[i];
        if(visit[visit[now.x]]!=visit[now.y])
        {
            int temp=visit[now.y];
            for(int i=0;i<max_size;i++)
            {

                if (visit[i]==temp)
                    visit[i]=visit[visit[now.x]];
            }
            cout<<now.x<<"->"<<now.y<<" "<<now.weight<<endl;
            count_cout_pair++;
        }
        if(count_cout_pair==node_count-1)//次数到了就能提前退出了
            break;
    }
}

void Graph::adj_to_apair()
{
    //now we have adj but apair is empty
    for (int i=0;i<max_size;i++)
    {
        for (int j=0;j<adj[i].size();i++)
        {
            if(adj[i][j].y>=i)
                apair.push_back(adj[i][j]);
        }
    }
}

void Graph::DFS_stack(void (*func)(int &))
{
    neaten_adj();
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
                        j=-1;
                        top=aa;
                    }
                }
                astack.pop();
            }
        }
    }
}

void Graph::DFS(void (*func)(int &))
{
    neaten_adj();
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
    }
}

void Graph::DFS_traverse(int &ver, bool *visited, void (*func)(int &),int & count_visited)
{
    if(count_visited==node_count)
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
    }
}

void Graph::neaten_adj()
{
    for (int i=0;i<max_size;i++)// ①
    {
        if (visit[i] != -1)
        {
            sort(adj[i].begin(),adj[i].end(),Cmp_y);
        }
    }
}

void Graph::BFS(void (*func)(int&))
{
    queue<int> q;
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
                        func(target);
                        q.push(target);
                    }
                }
                if(count_visited==node_count)
                    return;
                q.pop();
            }
        }
    }

}


