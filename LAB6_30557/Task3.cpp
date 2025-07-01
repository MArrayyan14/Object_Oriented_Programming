#include <iostream>
using namespace std;

class Student {
public:
    virtual double calculatePercentage() = 0; 
};

class StudentA : public Student {
private:
    double subj1, subj2, subj3;
public:
    StudentA(double s1, double s2, double s3) {
        subj1 = s1;
        subj2 = s2; 
        subj3 = s3;
    }
    
    double calculatePercentage() override {
        return (subj1 + subj2 + subj3) / 3.0;
    }
};

class StudentB : public Student {
private:
    double subj1, subj2, subj3, subj4;
public:
    StudentB(double s1, double s2, double s3, double s4) {
        subj1 = s1;
        subj2 = s2;
        subj3 = s3;
        subj4 = s4;
    }
    
    double calculatePercentage() override {
        return (subj1 + subj2 + subj3 + subj4) / 4.0;
    }
};

int main() {
    StudentA a(88, 76, 91);
    StudentB b(72, 85, 79, 90);

    cout << "Student A's Percentage: " << a.calculatePercentage() << "%" << endl;
    cout << "Student B's Percentage: " << b.calculatePercentage() << "%" << endl;

    return 0;
}
