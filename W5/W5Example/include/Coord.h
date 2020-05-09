#ifndef COORD_H
#define COORD_H
#include<iostream>
#include<ostream>
using namespace std;

class Coord
{
    public:
        Coord();
        Coord(int _x, int _y);
        Coord(const Coord &c);
        virtual ~Coord();
        Coord operator+(const Coord &right);
        Coord operator--();
        Coord& operator=(const Coord &right);
        void Print();

        friend ostream& operator<<(ostream& out, const Coord &right);




    protected:

        bool isZero();

    private:
        int x;
        int y;


};


ostream& operator<<(ostream& out, const Coord &right);


class Rect: public Coord{

public:
    Rect(int _x, int _y, int _xx, int _yy);
    void TestMembers();
    void Print();
    ~Rect();

private:
    int xx;
    int yy;

};

#endif // COORD_H
