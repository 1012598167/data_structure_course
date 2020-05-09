#include "top_k.h"

Top_k::Top_k()
{
    count = 0;
    cout<<"please input the value of k:";
    cin>>k;
}

void Top_k::max_heapify(int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && nums[son + 1] > nums[son]) //先比较两个子节点大小，选择最大的
            son++;
        if (nums[dad] > nums[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(nums[dad], nums[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}


void Top_k::add(Coordinate a)
{
    nums[count]=a;
    count++;
    if(count == k)
    {
        for (int i = k / 2 - 1; i >= 0; i--)
        {
            max_heapify(i, k - 1);
        }
    }
    else if(count > k)
    {
        if(nums[0] > nums[count-1])
        {
            swap(nums[0],nums[count-1]);
            max_heapify(0, k-1);
        }
    }
}

void Top_k::get_top_k()
{
    if(count<k)
    {
        for(int i=0; i<count;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
         for(int i=0; i<k;i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}
