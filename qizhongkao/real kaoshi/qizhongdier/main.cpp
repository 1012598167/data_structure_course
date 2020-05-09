#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
int main()
{
    int max=100;
    int aa;
    cin>>aa;
    getchar();
    while(aa--)
    {
        int yes=1;
        string str;
        getline(cin,str);
        int length=str.length();
        string a("(");
        string b("[");
        string c("{");
        string d(")");
        string e("]");
        string f("}");
        MyIntStack stack(max);
        for(unsigned int i=0;i<length;i++)
        {
            Stack_entry num;
            if (str.substr(i,1)==a)
            {
                num=1;
                stack.push(num);
            }
            else if(str.substr(i,1)==b)
            {
                num=2;
                stack.push(num);
            }
            else if(str.substr(i,1)==c)
            {
                num=3;
                stack.push(num);
            }
            else if(str.substr(i,1)==d)
            {
                Stack_entry r=1;
                if (r!=stack.pop())
                {
                    yes=0;
                    break;
                }
            }

            else if(str.substr(i,1)==e)
            {
                Stack_entry r=2;
                if (r!=stack.pop())
                {
                    yes=0;
                    break;
                }
            }
            else if(str.substr(i,1)==f)
            {
                Stack_entry r=3;
                if (r!=stack.pop())
                {
                    yes=0;
                    break;
                }
            }

        }
        if(yes==1)
        {
            if(stack.empty())
                cout<<"TRUE"<<endl;
            else
                cout<<"FALSE"<<endl;
        }
        else
            cout<<"FALSE"<<endl;
    }
    return 0;
}