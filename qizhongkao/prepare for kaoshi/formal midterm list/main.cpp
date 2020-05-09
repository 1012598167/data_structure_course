#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "List.h"
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
    List list;
    int aa,bb;
    cin>>aa>>bb;
    getchar();
    Node_entry cc;
    string pattern(" ");
    string str1;
    getline(cin,str1);
    vector<string>result1=split(str1,pattern);
    for (int i = 0; i < aa; i++)
    {
        list.add_from_tail(atoi(result1[i].c_str()));
    }


    string D("D");
    string G("G");
    string I("I");
    string L("L");
    string C("C");
    while(bb--)
    {
        string str;
        getline(cin,str);
        vector<string>result=split(str,pattern);
        if (result[0]==D)
        {
            Node*temp=list.get_Head();
            cout<<list.del(temp,atoi(result[1].c_str())-1)<<endl;
        }
        else if(result[0]==G)
        {
            Node*temp=list.get_Head();
            cout<<list.get(temp,atoi(result[1].c_str())-1)->entry<<endl;
        }


    }
    return 0;
}
/*int main()
{
    int max=30;
    MyIntStack stack1(max);
    int cishu;
    cin>>cishu;
    getchar();
    string pattern(" ");
    string instack("instack");
    string outstack("outstack");
    string getMin("getMin");
    while(cishu--)
    {
        string str;
        getline(cin,str);
        vector<string>result=split(str,pattern);
        if (result[0]==instack)
        {
            stack1.push(atoi(result[1].c_str()));
        }
        else if(result[0]==outstack)
            cout<<stack1.pop()<<endl;
        else if(result[0]==getMin)
        {
            int c;
            cout<<stack1.getMin()<<endl;
        }
    }
    return 0;
}*/
