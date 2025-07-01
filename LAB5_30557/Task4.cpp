#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    Animal(string name, int age) { 
        this->name = name;
        if(age >= 0){
            this->age = age;
        }
    }
};

class Lion : public Animal {
public:
    Lion(string n, int a) : Animal(n, a) {}

    void makeSound() {
        cout << name << " roars loudly!" << endl;
    }

    void displayInfo() {
        cout << "Lion - ";
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Snake : public Animal {
private:
    bool venomous;

public:
    Snake(string n, int a, bool venomous) : Animal(n, a){
        this->venomous = venomous;
    }

    void makeSound() {
        cout << name << " hisses softly!" << endl;
    }

    void displayInfo() {
        cout << "Snake - ";
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Venomous: " << (venomous ? "Yes" : "No") << endl;
    }
};

class Monkey : public Animal {
public:
    Monkey(string n, int a) : Animal(n, a) {}

    void makeSound() {
        cout << name << " chatters and swings playfully!" << endl;
    }

    void displayInfo() {
        cout << "Monkey - ";
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Lion lion("Simba", 5);
    Snake snake("Nagini", 3, true);
    Monkey monkey("George", 4);

    lion.makeSound();
    lion.displayInfo();

    cout << endl;

    snake.makeSound();
    snake.displayInfo();

    cout << endl;

    monkey.makeSound();
    monkey.displayInfo();

    return 0;
}
