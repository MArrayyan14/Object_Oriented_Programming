#include <iostream>
#include <string>
using namespace std;

class Person{
    
    private:
    int age;
    string name;

    public:
    Person(string name, int age){
        this->age = age;
        this->name = name;
    }
    int getAge() const {
        return age;
    }
    string getName() const {
        return name;
    }

};

class Student: public Person{

    private:
    int stID;

    public:
    Student(string name, int age, int stID) : Person(name,age){
        this->stID = stID;
    }
    void display(){
        cout<<"Name: "<<getName()<<", Age: "<<getAge()<<", ID: "<<stID<<endl;
    }

};


int main(){

    Student st1("Ammar", 20, 44810);
    Student st2("Arrayyan", 19, 30557);
    Student st3("Younus", 6, 30555);
    st1.display();
    st2.display();
    st3.display();

    return 0;
}