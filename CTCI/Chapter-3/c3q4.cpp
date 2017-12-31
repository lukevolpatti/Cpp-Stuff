// Queue via stacks
#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
private:
	stack<int> s1;
	stack<int> s2; // Temporary stack

public:
	void enqueue(int n);
	int dequeue();
};

void MyQueue::enqueue(int n){
	s1.push(n);
}

int MyQueue::dequeue(){
	int temp;

	if(!s2.empty()){
		temp = s2.top();
		s2.pop();
		return temp;
	}
	if(s1.empty()) return -1;

	while(!s1.empty()){
		temp = s1.top();
		s2.push(temp);
		s1.pop();
	}
	temp = s2.top();
	s2.pop();
	return temp;
}

int main(){
	MyQueue m;
	m.enqueue(1);
	m.enqueue(2);
	m.enqueue(3);
	cout << m.dequeue() << endl;
	cout << m.dequeue() << endl;
	cout << m.dequeue() << endl;
	cout << m.dequeue() << endl;
}