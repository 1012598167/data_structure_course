//
// Created by mathskiller on 2018/12/23.
//

#ifndef W10TUTORIAL_COORDINATE_H
#define W10TUTORIAL_COORDINATE_H

#include <iostream>
using namespace std;

class Coordinate
{
public:
    Coordinate(int x=0, int y=0);
    int get_x() const;
    int get_y() const;
private:
    int x_;
    int y_;
};

bool operator > (const Coordinate &a, const Coordinate &b);

ostream & operator << (ostream &output, Coordinate &a);


#endif //W10TUTORIAL_COORDINATE_H
