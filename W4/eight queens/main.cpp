#include <iostream>
#include "Queen.h"

using namespace std;
int main()
{
    int n;
    cin>>n;
    Queen q;
    q.size=n;
    q.DFS(0);
    cout << q.result << endl;
    return 0;
}