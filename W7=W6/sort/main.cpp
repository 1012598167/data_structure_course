#include <iostream>
#include "sort.h"
#include <map>
using namespace std;
typedef map<int,int> tmap;
typedef pair<int,int> tpair;

/*int main()
{
    int A[]={36,5,16,98,95,47,32,36,48,10};
    //ShellSort(A, 9);
    //QuickSort(A,0,5);
    //lsd_radix_sort(A,0,9,2);
    MergeSortRecursion(A,0,9);
    //cout<<getdigit(3783,1)<<endl;
    print(A,10);
    return 0;
}*/

int main()
{

    int a;
    cin>>a;
    int b=a;
    int c[100001];
    int i=0;
    while(b--)
        cin>>c[i++];
    int num;
    cin>>num;
    int tnum=num;
    int cc[100001];
    int j=0;
    while(tnum--)
        cin>>cc[j++];


    tmap mymap;
    for (int ii=0;ii<a;ii++)
    {
        mymap[c[ii]]=ii;
    }
    int tr=cc[0];
    tmap::iterator it;
    for(int iii=0;iii<num;iii++)
    {
        int find=cc[iii];
        it=mymap.find(find);
        if(it==mymap.end())
            cout<<-1<<endl;
        else
            cout<<it->second<<endl;
    }
    return 0;
}
