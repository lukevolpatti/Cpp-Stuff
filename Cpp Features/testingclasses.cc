#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    Animal();
    virtual ~Animal();
    void print();
private:
    int id;
};

class Dog : public Animal{
public:
    Dog();
    ~Dog();
    void print();
private:
    string breed;
};

Animal::Animal(){
    cout << "im in the default animal constructor" << endl;
    id = 0;
}

Animal::~Animal(){
    cout << "bye bye animal" << endl;
}

void Animal::print(){
    cout << "animal print" << endl;
}

Dog::Dog(){
    cout << "dog default constructor" << endl;
}

Dog::~Dog(){
    cout << "bye bye!" << endl;
}

void Dog::print(){
    cout << "woof!!" << endl;
} 
int main(){
    Animal a;
    a.print();
    Dog d;
    d.print();

    Animal* d1 = new Dog;
    d1->print();
    delete d1;
}
