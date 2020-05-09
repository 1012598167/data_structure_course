//
// Created by mathskiller on 2018/10/13.
//

#include <iostream>
#include "Queen.h"

using namespace std;

void Queen::DFS(int row)
{
/*    if(超过size) {
        表示找到一种解, result++;返回;}
    else{
        for(int z=0;z<size;z++){
            //如何判断成功?
            if(尝试放置到row行到z列成功)
                DFS(row+1);
        }*/
    if (row>=size)
    {
        result++;
        for (int i = 0; i < size; i++)
        {
                print[i][pos[i]]=1;
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout<<print[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i = 0; i < size; i++)
        {
            print[i][pos[i]]=0;
        }//clear for next print
        cout<<endl<<endl;
        return;
    }
    else
    {
        for (int z = 0; z < size; z++)
        {
            pos[row]=z;
            int success=1;
            for (int i = 0; i <= row; i++)
            {
                for (int j=0;j<i;j++)
                {
                    if (pos[j]==pos[i] or pos[j]-j==pos[i]-i or pos[j]+j==pos[i]+i)//不同行列 主对角线不重 副对角线不重
                    {
                        success=0;
                        break;break;
                    }
                }
            }
            if (success==1)
                DFS(row+1);
        }
    }
}

Queen::Queen()
{
    result=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            print[i][j]=0;
        }
    }
}
