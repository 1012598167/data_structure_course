//给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
// 你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。
// 注意这里下标的范围是 1 到 n，不是以 0 开头。数组是给定的，允许对数组建索引，每次的问题输入是target。
// 例： 给出 numbers = [2, 7, 11, 15],
//target = 9, 返回 [1, 2]。 Target 18, 返回 [2,3]。

#include <iostream>
#include <map>
using namespace std;
typedef map<int,int> tmap;
typedef pair<int,int> tpair;
tpair twoSum(tmap mymap,int target)
{
    tmap::iterator it = mymap.begin();
    tmap newmap;//(1,2)->(9-2,1)
    tmap reversemap;//(1,2)->(2,1)
    for (it=mymap.begin(); it!=mymap.end(); ++it)
    {
        newmap.insert(tpair(target-it->second,it->first));
        reversemap.insert(tpair(it->second,it->first));
    }
    for (it=mymap.begin(); it!=mymap.end(); ++it)
    {
        tmap::iterator newmapfind=newmap.find(it->second);
        if(newmapfind!=newmap.end())
        {
            int a=newmapfind->second;
            int b=reversemap.find(it->second)->second;
            tpair result(b,a);
            return result;
        }
    }
    tpair wrong(-1,-1);
    return wrong;
}

int main ()
{
    tmap mymap;
    int numbers[]={7,2,11,15};
    for (int i=0;i<sizeof(numbers)/ sizeof(int);i++)
        mymap.insert(tpair(i+1,numbers[i]));
    int target;
    cin>>target;
    tpair result=twoSum(mymap,target);
    tpair wrong(-1,-1);
    if (result!=wrong)
        cout<<result.first<<" "<<result.second<<endl;
    else
        cout<<"not found"<<endl;
    return 0;
}
/*
map<char,int> mymap;

// first insert function version (single parameter):
mymap.insert ( pair<char,int>('a',100) );
mymap.insert ( pair<char,int>('z',200) );

pair<map<char,int>::iterator,bool> ret;
ret = mymap.insert ( pair<char,int>('z',500) );
if (ret.second==false) {
cout << "element 'z' already existed";
cout << " with a value of " << ret.first->second << '\n';
}

// second insert function version (with hint position):
map<char,int>::iterator it = mymap.begin();
//mymap.insert (it, pair<char,int>('b',300));  // max efficiency inserting
//mymap.insert (it, pair<char,int>('c',400));  // no max efficiency inserting
mymap.insert (pair<char,int>('b',300));  // max efficiency inserting
mymap.insert (pair<char,int>('b',400));

// third insert function version (range insertion):
map<char,int> anothermap;
anothermap.insert(mymap.begin(),mymap.find('c'));

// showing contents:
cout << "mymap contains:\n";
for (it=mymap.begin(); it!=mymap.end(); ++it)
cout << it->first << " => " << it->second << '\n';

cout << "anothermap contains:\n";
for (it=anothermap.begin(); it!=anothermap.end(); ++it)
cout << it->first << " => " << it->second << '\n';
 */