#include "Point.h"
#include <iostream>

using namespace std;

int main(){
    Point po1(5,9);
    Point po2(1,2);
    
    Point po3 = po1 + po2;
    Point po4 = po1 - po2;
    Point po5 = po1 * 2;
    Point po6 = po1;

    cout<<"p1 + p2 = Point"<<po3<<endl<<"p1 - p2 = Point"<<po4<<endl<<"p1 * 2 = Point"<<po5<<endl<<"After assignment p6= "<<po6<<endl;
    cout<<"Is p6 == p1? ";
    if(po6 == po1){
        cout<<"yes"<<endl;
    }
    cout<<"Length of p1: "<<Length(po1)<<endl;
    cout<<"Length of p2: "<<Length(po2)<<endl;


    return 0;
}