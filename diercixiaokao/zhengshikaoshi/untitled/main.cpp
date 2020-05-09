#include<stdio.h>

int main()
{
    int u10;
    char u16[10];
    int w=0,a,b,i;

    scanf("%d",&u10);
    if(u10==0)
    {
        u16[0]='0';
        w++;
    }
    else
    {
        a=u10;
        while(a)
        {
            b=a%16;
            if(b<10)
            {
                u16[w]='0'+b;
            }
            else
            {
                u16[w]='A'+b-10;
            }
            a=a/16;
            w++;
        }
    }
    //printf("%d(10)转换为16进制数字为：",u10);
    for(i=w-1;i>=0;i--)
    {
        printf("%c",u16[i]);
    }
    return 0;
}


