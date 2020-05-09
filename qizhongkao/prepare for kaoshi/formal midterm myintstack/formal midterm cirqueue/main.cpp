#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include "CirQueue.h"
using namespace std;

vector<string> split(string &str, const string &pattern)//pattern 以该字符分隔
{
    unsigned int pos;
    vector<string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    unsigned int i;
    for(i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

int main()
{
    int max=30;
    CirQueue q1(max);
    int cishu;
    cin>>cishu;
    getchar();
    string pattern(" ");
    string enqueue("enqueue");
    string dequeue("dequeue");
    while(cishu--)
    {
        string str;
        getline(cin,str);
        vector<string>result=split(str,pattern);
        if (result[0]==enqueue)
        {
            q1.push(atoi(result[1].c_str()));
        }
        else if(result[0]==dequeue)
            cout<<q1.pop()<<endl;
    }
    return 0;
}