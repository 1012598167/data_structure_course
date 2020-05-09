#include "coordinate.h"

Coordinate::Coordinate(int x, int y)
{
    x_ = x;
    y_ = y;
}

int Coordinate::get_x() const
{
    return x_;
}

int Coordinate::get_y() const
{
    return y_;
}

bool operator > (const Coordinate &a, const Coordinate &b)
{
    if(a.get_x() != b.get_x())
    {
        return a.get_x()>b.get_x();
    }
    else
    {
        return a.get_y()>b.get_y();
    }
}

ostream & operator << (ostream &output, Coordinate &a)
{
    output<<"<"<<a.get_x()<<","<<a.get_y()<<">";
    return output;
}
