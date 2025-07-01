#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point :: Point(int x, int y){
    this->x = x;
    this->y = y;
}

Point Point :: operator+(const Point& other){
    Point p1;
    p1.x = this->x + other.x;
    p1.y = this->y + other.y;

    return p1;
}
Point Point :: operator-(const Point& other){
    Point p1;
    p1.x = this->x - other.x;
    p1.y = this->y - other.y;

    return p1;
}
Point Point :: operator*(const int scalar){
    Point p1;
    p1.x = this->x * scalar;
    p1.y = this->y * scalar;

    return p1;
}
bool Point :: operator==(const Point& other){
    if(this->x == other.x && this->y == other.y){
        return true;
    }
    else
        return false;
}
Point Point :: operator=(const Point& other){
    if (this != &other) { 
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
}

double Length(Point& p){
    int num = (p.x * p.x) + (p.y * p.y);
    return sqrt(num);
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(";
    out << p.x;
    out << ", ";
    out << p.y;
    out << ")";

    return out;
}