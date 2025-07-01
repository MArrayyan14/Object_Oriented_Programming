#include <iostream>
#include "circle.h"  

using namespace std;

int main() {
    Circle circle;  
    float radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    circle.setRadius(radius);
    cout << "Radius: " << circle.getRadius() << endl;
    cout << "Circumference: " << circle.circumference() << endl;

    return 0;
}
