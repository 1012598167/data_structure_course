
//
// Created by mathskiller on 2018/11/5.
//

#ifndef DIWUCIZUOYE_KEY_H
#define DIWUCIZUOYE_KEY_H


class Key
{
    int key;
public:
    //Key (int x=0):key(x){};��������ϰ�߲���//�������ò������б�����
    explicit Key (int x=0):key(x){}//��ֹ��ʽת��due to���ι���
    int the_key()const{return key;}
};

#endif //DIWUCIZUOYE_KEY_H
