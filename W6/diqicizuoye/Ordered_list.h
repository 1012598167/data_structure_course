//
// Created by mathskiller on 2018/10/29.
//

#ifndef DIWUCIZUOYE_ORDERED_LIST_H
#define DIWUCIZUOYE_ORDERED_LIST_H
//#include "Key.h"
#include"Record.h"
#include"List.cpp"


class Ordered_list: public List<Record>
{
public:
    Error_code insert(const Record &data);
    Error_code insert(int position, const Record &data);
    Error_code replace(int position, const Record &data);
    Error_code recursive_binary(const Ordered_list &the_list, const Key &target, int bottom, int top, int &position);
};


#endif //DIWUCIZUOYE_ORDERED_LIST_H