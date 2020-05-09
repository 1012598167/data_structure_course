//
// Created by mathskiller on 2018/12/18.
//

#ifndef LIST_MERGE_RECORD_H
#define LIST_MERGE_RECORD_H
#include "Key.h"
class Record
{
public:
    Record(int y=0):akey(1),record_entry(y){}
    Key get_Key()const{return akey;}
    bool operator ==(Key &y) const
    {
        return this->get_Key().the_key()==y.the_key();
    }
    bool operator <=(Record &y) const
    {
        return this->record_entry<=y.record_entry;
    }
    int the_record()const{return record_entry;}
private:
    Key akey;
    int record_entry;
};


#endif //LIST_MERGE_RECORD_H
