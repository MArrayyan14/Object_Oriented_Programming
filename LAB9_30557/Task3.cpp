#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Employee {
public:
    int id;
    string name;
    string department;
    double salary;

    Employee() = default;
    Employee(int idp, string namep, string deptp, double salaryp){
        id=idp;
        name=namep;
        department=deptp;
        salary=salaryp;
    }
};

class EmployeeManager {
private:
    map<int, Employee> emprecords;

public:
    void addEmployee(const Employee& emp) {
        emprecords[emp.id] = emp;
    }

    void deleteEmployee(int id) {
        if (emprecords.erase(id))
            cout<<"Employee with ID "<<id<<" deleted."<<endl;
        else
            cout<<"Employee not found."<<endl;
    }

    void displayAll(void (*displayFunc)(const Employee&)) const {
        for (const auto& pair : emprecords) {
            displayFunc(pair.second);
        }
    }

    void sortEmployees(const function<bool(const Employee&, const Employee&)>& comp) const {
        vector<Employee> vec;
        for (const auto& pair : emprecords)
            vec.push_back(pair.second);

        sort(vec.begin(), vec.end(), comp);

        for (const auto& emp : vec)
            simpleDisplay(emp);
    }

    void findHighEarners(double amount) const {
        cout<< "Employees earning above "<<amount<<endl;
        for_each(emprecords.begin(), emprecords.end(), [amount](const auto& pair) {
            if (pair.second.salary > amount)
                simpleDisplay(pair.second);
        });
    }

    void calculateAverageSalary() const {
        if (emprecords.empty()) {
            cout << "No records to calculate average.\n";
            return;
        }

        double total = 0.0;
        for (const auto& pair : emprecords) {
            total += pair.second.salary;
        }

        double average = total / emprecords.size();
        cout<<"Average salary: "<<average<<endl;
    }

    static void simpleDisplay(const Employee& emp) {
        cout<<"ID: "<<emp.id<< ", Name: "<<emp.name<<", Salary: "<<emp.salary<<endl;
    }

    static void fullDisplay(const Employee& e) {
        cout<<"ID: "<<e.id<<", Name: "<<e.name<< ", Dept: "<<e.department<<", Salary: "<<e.salary<<endl;
    }
};

struct SortByName {
    bool operator()(const Employee& a, const Employee& b) const {
        return a.name < b.name;
    }
};

bool sortBySalary(const Employee& a, const Employee& b) {
    return a.salary > b.salary;
}

int main() {
    EmployeeManager employ;
    employ.addEmployee({1, "Ameer", "HR", 5000});
    employ.addEmployee({2, "Arrayan", "Finance", 6000});
    employ.addEmployee({3, "Younus", "IT", 70000});
    employ.addEmployee({4, "Rayyan", "Marketing", 80000});
    cout << "All Employees (Full Display):"<<endl;
    employ.displayAll(EmployeeManager::fullDisplay);
    cout << "Sorted by Name:"<<endl;
    employ.sortEmployees(SortByName());
    cout << "Sorted by Salary:"<<endl;
    employ.sortEmployees(sortBySalary);
    cout << "Sorted by ID:"<<endl;
    employ.sortEmployees([](const Employee& a, const Employee& b) {
        return a.id < b.id;
    });
    cout << "Employee Salary > 6000):"<<endl;
    employ.findHighEarners(6000);
    cout << "Average Salary:"<<endl;
    employ.calculateAverageSalary();
    cout << "Delete Employee with ID 2:"<<endl;
    employ.deleteEmployee(2);
    cout << "All Employees (Simple Display):"<<endl;
    employ.displayAll(EmployeeManager::simpleDisplay);
    return 0;
}