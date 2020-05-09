
//
// Created by mathskiller on 2018/11/5.
//

#ifndef DIWUCIZUOYE_KEY_H
#define DIWUCIZUOYE_KEY_H


class Key
{
    int key;
public:
    //Key (int x=0):key(x){};这样代码习惯不好//单参数用参数化列表不合适
    explicit Key (int x=0):key(x){}//防止隐式转换due to单参构造
    int the_key()const{return key;}
};

#endif //DIWUCIZUOYE_KEY_H
