// Virtual Keyword
// An example of using the virtual keyword for late/dynamic binding in
// inheritance.

#include <iostream>
#include <string>
using namespace std;

class Animal{
private:
	int legs;
public:
	Animal(){cout << "Animal default constructor" << endl;}
	Animal(int _legs);
	void setLegs(int _legs){legs = _legs;}
	int getLegs(){return legs;}
	virtual void print(){cout << "Animal's print. Number of legs: " << legs << endl;}
};

class Dog : public Animal{
private:
	string breed;
public:
	Dog();
	Dog(string _breed){breed = _breed;}
	void setBreed(string _breed){breed = _breed;}
	string getBreed(){return breed;}
	void print(){Animal::print(); cout << "Dog's print. Breed: " << breed << endl;}
};


int main(){
	Animal A;
	Animal* Aptr = new Dog("beagle");
	Aptr->print();
}