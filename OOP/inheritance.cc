#include <iostream>
using namespace std;

class Base{
private:
	int val;
public:
	Base();
	Base(int n);
	void setVal(int n){val = n;}
	int getVal(){return val;}
	void print(){cout << "Base's value: " << val << endl;}
};

class Derived : public Base{
private:
	int val2;
public:
	Derived();
	Derived(int n);
	Derived(int n1, int n2);
	void setVal2(int n){val2 = n;}
	int getVal2(){return val2;}
	void print(){Base::print(); cout << "Derived's value: " << val2 << endl;}
};

Base::Base(){
	cout << "Default base constructor" << endl;
}

Base::Base(int n){
	cout << "Base constructor called with input " << n << endl;
}

Derived::Derived(){
	cout << "Default derived constructor" << endl;
}

Derived::Derived(int n){
	cout << "Derived constructor call with input " << n << endl;
}

Derived::Derived(int n1, int n2) : Base(n1){
	cout << "Called base constructor with input " << n1 << endl;
	cout << "Then called derived constructor with input " << n2 << endl;
	val2 = n2;
}

int main(){
	Derived d;
	d.setVal2(10);
	cout << d.getVal2() << endl;
	d.setVal(5);
	cout << d.getVal() << endl;
	d.Base::print();

	Derived d2(0, 1);
	d2.print();

	Base* basePtr = &d;
	basePtr->print();
	//basePtr->setVal2(23); Results in error!
	
}