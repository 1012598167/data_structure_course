//
// Created by mathskiller on 2018/11/5.
//

#ifndef DIWUCIZUOYE_RECORD_H
#define DIWUCIZUOYE_RECORD_H

#include "Key.h"
class Record
{
public:
    Record(int x=0,int y=0):key(x),other(y){}
    operator Key();
    int the_key()const{return key;}
    bool operator ==(const Record &y) const
    {
        return this->the_key()==y.the_key();
    }
    bool operator >(const Record &y) const
    {
        return this->the_key()>y.the_key();
    }
    bool operator <(const Record &y) const
    {
        return this->the_key()<y.the_key();
    }
    bool operator >=(const Record &y) const
    {
        return this->the_key()>=y.the_key();
    }
    bool operator <=(const Record &y) const
    {
        return this->the_key()<=y.the_key();
    }
    bool operator !=(const Record &y) const
    {
        return this->the_key()!=y.the_key();
    }
    bool operator ==(const Key &y) const
    {
        return this->the_key()==y.the_key();
    }
    bool operator <(const Key &y) const
    {
        return this->the_key()==y.the_key();
    }
private:
    int key;
    int other;
};


#endif //DIWUCIZUOYE_RECORD_H
