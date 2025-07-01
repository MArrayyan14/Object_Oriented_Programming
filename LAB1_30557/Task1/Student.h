#ifndef _Student_h
#define _Student_h
    
#include <string>
using namespace std;

class Student{

    public:
    string courses[6];
    Student();
    Student(int id, string& Name, float CGPA, string courses);
    void DisplayCourses(string courses[]);
    int getStID() const;
    string getStName() const;
    float getCGPA() const;

    private:
    int id;
    string Name;
    float CGPA;


};

#endif