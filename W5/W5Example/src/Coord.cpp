#include "Coord.h"


Coord::Coord()
{
    //ctor
    x=0;
    y=0;
}


Coord::Coord(int _x, int _y):x(_x), y(_y){
    x=_x;
    y=_y;
}

Coord::Coord(const Coord &c){
    this->x=c.x;
    y=c.y;
}


Coord Coord::operator+(const Coord &right){
    return Coord(right.x+x,right.y+y);
}

Coord Coord::operator--(){
    x--;
    y--;
    return *this;
}



Coord& Coord::operator=(const Coord &right){
    x=right.x;
    y=right.y;
    return *this;
}


void Coord::Print(){
    cout<<x<<" "<<y<<endl;

}

bool Coord::isZero(){
    return x==0&&y==0;
}

Coord::~Coord()
{
    //dtor
    cout<<"Coord:"<<x<<","<<y<<" is destroyed"<<endl;

}


ostream& operator<<(ostream& out, const Coord &right){
    out<<right.x<<" "<<right.y<<endl;
    return out;
}


// Constructor 1
Rect::Rect(int _x, int _y, int _xx, int _yy):Coord(_x,_y){
    xx=_xx;
    yy=_yy;
}


/*
// Constructor 2
Rect::Rect(int _x, int _y, int _xx, int _yy){
    x=_x;
    y=_y;
    xx=_xx;
    yy=_yy;
}
*/


void Rect::TestMembers(){
  // cout<<x<<" "<<y<<endl;
  // isZero();
  cout<<"Func TestMembers"<<endl;
  Coord::Print();
  Print();

}

void Rect::Print(){
  Coord::Print();
  cout<<xx<<" "<<yy<<endl;
}

Rect::~Rect(){
    cout<<"Rect:"<<xx<<","<<yy<<" is destroyed!"<<endl;
}


