#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
//字符串分割函数
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

int main()//字符串分割 输入huan,ss,sss 分割符
{
    string str;
    cout<<"Please input str:"<<endl;
    getline(cin,str);
    cout<<str<<endl;
    string pattern;
    cout<<"Please input pattern:"<<endl;
    //cin>>pattern;
    getline(cin,pattern);//用于获取含空格的字符串
    vector<string> result=split(str,pattern);
    cout<<"The result:"<<endl;
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }


    return 0;
}

/*
int main()
{
    //while(cin>>a>>b&&终止条件) 用ctrl+z终止 可输入无穷个
    //cin 遇空格结束
    //char a;a=cin.get();//只读一个字符
    //char a[20];cin.get(a,20);//可空格 定max长//n-1个字符+\0
    //char a[20];cin.getline(a,20,'a');//可设终止 必须用该字符终止
    //#include<string>;string str;getline(cin,str);//cout<<str<<endl;
    */
/*#include <string>
    #include <fstream>
    ifstream in("test.txt");
    string filename;
    string line;
    if(in)
    {
        while(getline(in,line))
            cout<<line<<endl;
    }
    else
        cout<<"no such file"<<endl;*//*

    //str.find(substr,pos) substr为子字符串 pos为初始查找位置  查找子字符串第一次出现位置
    // str.substr（start,end) 获得子字符串

    return 0;
}*/
