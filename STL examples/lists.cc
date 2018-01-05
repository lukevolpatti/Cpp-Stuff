#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> l;
	l.push_front(1);
	l.push_back(2);
	cout << "Size: " << l.size() << endl;
	cout << l.front() << endl;
	cout << l.back() << endl;
}