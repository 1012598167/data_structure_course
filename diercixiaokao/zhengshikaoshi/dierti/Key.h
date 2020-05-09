//
// Created by mathskiller on 2018/12/29.
//

#ifndef DISANTI_KEY_H
#define DISANTI_KEY_H
#define NULL nullptr
class Key
{
public:
    Key (int x=0):key(x){}
    int the_key()const{return key;}
private:
    int key;
};


#endif //DISANTI_KEY_H
