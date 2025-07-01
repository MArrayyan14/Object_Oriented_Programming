#ifndef _Point_h
#define _Point_h

#include <iostream>
using namespace std;

class Point {
    public:
    Point(int x=0, int y=0);
    Point operator+(const Point& other);
    Point operator-(const Point& other);
    Point operator*(const int scalar);
    bool operator==(const Point& other);
    Point operator=(const Point& other);
    friend double Length(Point& p);     
    friend ostream& operator<<(ostream& out, const Point& p);    

    private:
    int x;
    int y;
};


#endif