// Principles of OOP
// A simple program to illustrate the four principles of OOP: inheritance,
// abstraction, encapsulation, and polymorphism.
#include<iostream>
using namespace std;

class Vehicle{
// Abstraction: Certain implementation details are kept from the user; 
// they may only interact with the class through public functions.
private:
	bool hasWheels;

public:
	Vehicle();
	Vehicle(bool _hasWheels);

	// Encapsulation: we have accessors and mutators to restrict access to
	// certain members.
	bool getWheels();
	void setWheels(bool _hasWheels);
	void print();
};

Vehicle::Vehicle(){

}

Vehicle::Vehicle(bool _hasWheels){
	hasWheels = _hasWheels;
}

bool Vehicle::getWheels(){
	return hasWheels;
}

void Vehicle::setWheels(bool _hasWheels){
	hasWheels = _hasWheels;
} 

void Vehicle::print(){
	cout << "Vehicle's print function" << endl;
}



// Inheritance: the Car class inherits public memebers of Vehicle.
class Car : public Vehicle{
private:
	int numWheels;
public:
	Car();
	Car(int _numWheels);
	int getNumWheels();
	void setNumWheels(int _numWheels);

	// Polymorphsim (overriding)
	void print();

	// Polymorphism (overloading)
	void print(bool printNumWheels);
};

Car::Car(){
	setWheels(true);
	numWheels = 4;
}

Car::Car(int _numWheels){
	setWheels(true);
	numWheels = _numWheels;
}

int Car::getNumWheels(){
	return numWheels;
}

void Car::setNumWheels(int _numWheels){
	numWheels = _numWheels;
}

void Car::print(){
	cout << "Car's print function" << endl;
}

void Car::print(bool printNumWheels){
	if(printNumWheels) cout << "There are " << numWheels << " wheels" << endl;
	else cout << "Not going to print numWheels!" << endl;
}

int main(){
	Vehicle v(true);
	v.print();

	Car c(5);
	c.print();
	c.print(true);
	c.print(false);
}