#include <iostream>
#include "Student.h"

using namespace std;

Student :: Student(){
    cout<<"Enter Student ID: ";
    cin>>id;

    cout<<"Enter Student Name: ";
    cin>>Name;

    cout<<"Enter Student CGPA: ";
    cin>>CGPA;

    for(int i=0; i<6; i++){
        cout<<"Enter the name of Course #"<<i+1<<" : ";
        cin>>courses[i];
    }

}

Student :: Student(int id, string& Name, float CGPA, string courses){
    this->id = id;
    this->Name = Name;
    this->CGPA = CGPA;
}

void Student :: DisplayCourses(string courses[]){
    for(int i = 0; i<6; i++){
        cout<<"Course "<<i+1<<": "<<courses[i]<<endl;
    }
}

int Student :: getStID() const {
    return id;
}

string Student :: getStName() const {
    return Name;
}

float Student :: getCGPA() const {
    return CGPA;
}