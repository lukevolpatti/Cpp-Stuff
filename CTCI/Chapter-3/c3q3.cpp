// Stack of plates
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct SetOfStacks{
	int threshold; 
	int currStack;
	vector<stack<int> > v;

	SetOfStacks(int thresh);
	void push(int n);
	int pop();
	int popAt(int index);
};

SetOfStacks::SetOfStacks(int thresh){
	threshold = thresh;
	currStack = -1;
}

void SetOfStacks::push(int n){
	// Check to see if either curr stack is full or no stacks are allocated
	if(currStack == -1 || v[currStack].size() == threshold){
		// Need to allocate new stack:
		if(currStack + 1 == v.size()){
			stack<int> s;
			v.push_back(s);
		}
		currStack++;
	}
	v[currStack].push(n);
}

int SetOfStacks::pop(){
	int temp;
	// Check if we can't pop from current stack
	if(currStack == -1 || v[currStack].empty()){
		// All stacks are empty, return -1 for error
		if(currStack == 0 || currStack == -1) return -1;
		else{
			while(v[currStack].empty()){
				currStack--;
				if(currStack < 0) return -1;
			}
			temp = v[currStack].top();
			v[currStack].pop();
			return temp;
		}
	}
	else{
		temp = v[currStack].top();
		v[currStack].pop();
		return temp;
	}
}


// For the follow-up(implemented below), I assume that popping from a
// particular stack will now affect the stack around it, i.e. they will not
// be modified to rebalance the entire data structure.
int SetOfStacks::popAt(int index){
	if(index >= v.size()) return -1;
	if(index < 0) return -1;
	if(v[index].empty()) return -1;

	int temp = v[index].top();
	v[index].pop();
	return temp;
}

int main(){
	SetOfStacks s(2);
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.popAt(0) << endl;
	cout << s.popAt(0) << endl;
	cout << s.popAt(0) << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
}