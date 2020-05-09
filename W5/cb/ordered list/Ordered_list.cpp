//
// Created by mathskiller on 2018/10/29.
//

#include "Ordered_list.h"

Error_code Ordered_list::insert(const Record &data)
{
  /*  int position;
    for (position = 0; position < size(); position++)
    {
        Record list_data;
        retrieve(position,list_data);
        if (data >= list_data)
        {
            break;
        }
    }*/
    //return List<Record>::insert(position,data);
    return success;
}
/*
Error_code Ordered_list::insert(int position, const Record &data)
{
    Record list_data;
    if (position>0)
    {
        retrieve(position-1,list_data);
        if (data<list_data)
            return fail;
    }
    if(position<size())
    {
        retrieve(position,list_data);
        if (data>list_data)
            return fail;
    }
    return List<Record>::insert(position, data);
}

Error_code Ordered_list::replace(int position, const Record &data)
{
    if (position<=0 or position>=size())
        return fail;
    Record list_data_left;
    Record list_data_right;
    retrieve(position-1,list_data_left);
    retrieve(position,list_data_right);
    if (data<list_data_left or data>list_data_right)
        return fail;
    return List<Record>::replace(position, data);
}
*/
