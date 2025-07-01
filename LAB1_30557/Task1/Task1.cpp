#include <iostream>
#include "Student.h"
#include <string>

using namespace std;

int main(){
    Student s1;
    cout<<endl<<"Name: "<<s1.getStName()<<endl<<"ID: "<<s1.getStID()<<endl<<"CGPA: "<<s1.getCGPA()<<endl;
    s1.DisplayCourses(s1.courses);
    
    return 0 ;

}
