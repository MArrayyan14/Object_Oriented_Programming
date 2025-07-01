#ifndef _circle_h
#define _circle_h

class Circle {
private:
    float radius; 
public:
    void setRadius(float r);
    float getRadius() const;
    float circumference() const;
};
#endif
