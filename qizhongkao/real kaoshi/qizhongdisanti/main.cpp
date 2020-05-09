#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

/*void perm(int list[],int low,int high,int &count){
    if(low==high){//当low==high时,此时list就是其中一个排列,输出list
        for(int i=0;i<=low;i++)
        {
            cout<<list[i];

        }
        count++;
        cout<<endl;
    }else{
        for(int i=low;i<=high;i++){//每个元素与第一个元素交换
            swap(list[i],list[low]);
            perm(list,low+1,high,count);//交换后,得到子序列,用函数perm得到子序列的全排列
            swap(list[i],list[low]);//最后,将元素交换回来,复原,然后交换另一个元素
        }
    }
}*/

void perm1(int list[],int n,int &count)
{
    int j=n-2;
    while(list[j]>list[j+1])
    {
        j--;//j is the max index satisfying list[j]>list[j+1]
        if (j==-1)
            return;
    }
    int k=n-1;
    while(list[j]>list[k])
        k--;//list[k] is the smallest number on the right side of list[j] which is bigger then list[j]
    swap(list[j],list[k]);
    int r=n-1;
    int s=j+1;
    while (r>s)
    {
        swap(list[r],list[s]);
        r--;
        s++;
    }//those after a[j] manifest increasing
    for(int i=0;i<n;i++)
    {
        cout<<list[i];
    }
    count++;
    cout<<endl;
    perm1(list,n,count);
}

int main()
{
    int n;
    cin>>n;
    //int count=0;
    int count=1;
    int list[]={1,2,3,4,5,6,7,8,9};
    if(1<=n && n<=9)
    {
        //perm(list,0,n-1,count);
        for(int i=0;i<n;i++)
        {
            cout<<list[i];
        }
        cout<<endl;
        perm1(list,n,count);
        cout<<count<<endl;
    }
    else
        cout<<-1<<endl;


    return 0;
}