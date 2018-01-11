// Number swapper
#include <iostream>
using namespace std;

void swap(int& a, int& b){
	a = a + b;
	b = a - b;
	a = a - b;
}

int main(){
	int a = 3;
	int b = 5;
	cout << a << b << endl;
	swap(a, b);
	cout << a << b << endl;
}