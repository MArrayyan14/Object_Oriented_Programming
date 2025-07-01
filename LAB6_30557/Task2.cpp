#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Animal {
protected:
    int legs;

public:
    Animal(int legs) {
        this->legs = legs;
    }
    virtual void walk() = 0;
    virtual void eat() = 0;
};

class Pet {
public:
    virtual string getName() = 0;
    virtual void setName(string name) = 0;
    virtual void play() = 0;
};

class Spider : public Animal {
public:
    Spider() : Animal(8) {}
    void walk() override {
        cout << "Spider crawls and has " << legs << " legs." << endl;
    }
    void eat() override {
        cout << "Spider eats insects." << endl;
    }
};

class Cat : public Animal, public Pet {
private:
    string name;

public:
    Cat() : Animal(4) {
        name = "Unknown";
    }

    Cat(string name) : Animal(4) {
        this->name = name;
    }

    void walk() override {
        cout << "Cat " << name << " walks and has " << legs << " legs." << endl;
    }

    void eat() override {
        cout << "Cat " << name << " eats cat food." << endl;
    }

    string getName() override {
        return name;
    }

    void setName(string newName) override {
        name = newName;
    }

    void play() override {
        cout << "Cat " << name << " plays with a ball." << endl;
    }
};

class Fish : public Animal, public Pet {
private:
    string name;

public:
    Fish() : Animal(0) {
        name = "Unknown";
    }

    Fish(string name) : Animal(0) {
        this->name = name;
    }

    void walk() override {
        cout << "Fish " << name << " doesnt walk." << endl;
    }

    void eat() override {
        cout << "Fish " << name << " eats fish food." << endl;
    }

    string getName() override {
        return name;
    }

    void setName(string newName) override {
        name = newName;
    }

    void play() override {
        cout << "Fish " << name << " plays with smaller fish." << endl;
    }
};

int main() {
    vector<Animal*> animals;
    vector<Pet*> pets;

    Spider spider;
    Cat cat("billi");
    Fish fish("macchi");

    animals.push_back(&spider);
    animals.push_back(&cat);
    animals.push_back(&fish);

    pets.push_back(&cat);
    pets.push_back(&fish);

    for (Animal* animal : animals) {
        animal->walk();
        animal->eat();
    }

    for (Pet* pet : pets) {
        pet->play();
    }

    return 0;
}
