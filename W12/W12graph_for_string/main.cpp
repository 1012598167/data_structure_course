#include <iostream>
#include "Graph.h"
int main()
{
/*input
0 1 6
3 0 4
1 3 7
2 1 10
1 4 7
3 2 8
3 4 12
2 5 6
2 4 5
4 5 7
-1 -1 -1
*/
/*input
0 1 1
1 2 7
3 2 8
1 4 10
0 4 6
5 4 4
0 8 5
8 5 3
5 6 2
5 9 9
-1 -1 -1
*/
/*input
0 1 1
1 2 7
3 2 8
1 4 10
0 4 6
5 4 4
0 8 5
8 5 3
5 6 2
6 7 9
-1 -1 -1
*/
    Graph graph;
    graph.Kruskal();
    /*graph.DFS(graph.print_int);
    cout<<endl;
    graph.BFS(graph.print_int);
    cout<<endl;*/
    graph.DFS_stack(graph.print_int);
    return 0;
}