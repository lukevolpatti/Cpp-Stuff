#include <stack>
#include <iostream>
using namespace std;

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "Current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.empty() << endl;
}