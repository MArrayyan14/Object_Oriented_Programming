#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string Name;
    double Salary;

public:
    Employee(string Name, double Salary) {
        this->Name = Name;
        this->Salary = Salary;
    }
    virtual void calculateBonus() const = 0;
    void name(){
        cout<<Name;
    }
    void salary(){
        cout<<Salary;
    }
};

class Ipromotable {
public:
    virtual void promote(double newSalary) = 0;
};

class Manager : public Employee, public Ipromotable {
public:
    Manager(string Name, double Salary) : Employee(Name, Salary) {}

    void calculateBonus() const override {
        cout << Salary * (10.0 / 100) << endl; 
    }

    void promote(double newSalary) override {
        cout << "Manager " << Name << " promoted from $" << Salary << " TO $";
        Salary = newSalary;
        cout << Salary << endl; 
    }
};

class Programmer : public Employee, public Ipromotable {
public:
    Programmer(string Name, double Salary) : Employee(Name, Salary) {}

    void calculateBonus() const override {
        cout << Salary * (5.0 / 100) << endl; 
    }

    void promote(double newSalary) override {
        cout << "Programmer " << Name << " promoted from $" << Salary << " TO $";
        Salary = newSalary;
        cout << Salary << endl; 
    }
};

int main() {
    Programmer p1("ALI", 3000);
    Manager m1("Ahmed", 5000);

    p1.name();
    cout<<"\t";
    p1.calculateBonus();
    m1.name();
    cout<<"\t";
    m1.calculateBonus();

    p1.promote(5000);
    m1.promote(6900);

    p1.name();
    cout<<"'s New Bonus: ";
    p1.calculateBonus();

    m1.name();
    cout<<"'s New Bonus: ";
    m1.calculateBonus();    
    return 0;
}
