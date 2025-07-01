#include "circle.h"
#include <cmath>  

void Circle::setRadius(float r) {
    radius = r;
}
float Circle::getRadius() const {
    return radius;
}
float Circle::circumference() const {
    return 2 * M_PI * radius; 
}
