//
// Created by mathskiller on 2018/12/18.
//

#ifndef LIST_MERGE_KEY_H
#define LIST_MERGE_KEY_H
#define NULL nullptr

class Key
{
public:
    Key (int x=0):key(x){}
    int the_key()const{return key;}
private:
    int key;
};


#endif //LIST_MERGE_KEY_H
