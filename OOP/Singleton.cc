// A simple implementation of the singleton design pattern
#include<iostream>
using namespace std;

class S{
public:
	static S& getInstance(){
		static S instance;
		return instance;
	}

private:
	// Make constructor private so the only way to instantiate the class is
	// through getInstance().
	S(){}
};

int main(){
	S* ptr = &(S::getInstance());
	S* ptr2 = &(S::getInstance());

	cout << ptr << " " << ptr2 << endl;
}