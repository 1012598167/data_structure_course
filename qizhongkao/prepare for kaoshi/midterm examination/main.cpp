#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<cstdlib>
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
    int mm,nn;
    cin>>mm>>nn;
    string str1;
    getline(cin,str1);
    while(nn--)
    {
        string str;
        getline(cin,str);
        string pattern(" ");
        vector<string> result=split(str,pattern);
        //result[1]=atoi(result[1].c_str());
        int aa=atoi(result[1].c_str());
        if(result[0]=="D")
        {
            //cout<<"DDDDDD"<<result[1]<<endl;
            cout<<"DDDDDD"<<aa<<endl;
        }
    }
    string pattern;
    cout<<"Please input pattern:"<<endl;
    //cin>>pattern;
    getline(cin,pattern);//用于获取含空格的字符串



    return 0;
}
