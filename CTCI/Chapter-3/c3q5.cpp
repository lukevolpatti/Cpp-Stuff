// Sort stack
#include <iostream>
#include <stack>
using namespace std;

// Approach 1
// Iterate through the stack s1. At each iteration number, put that many
// elements in a teporary stack s2. Remove the top element from s1. Store in
// temp var. Start popping from s2 and pushing to s1. If the temp var is ever
// bigger than the current s2 top, then insert the temp var to s1 and continue
// on popping from s2 and pushing to s1.
stack<int> sort(stack<int>& s1){
	stack<int> s2;

	for(int iter = 0; iter < s1.size(); iter++){
		for(int i = 0; i < iter; i++){
			s2.push(s1.top());
			s1.pop();
		}

		int temp = s1.top();
		s1.pop();
		bool hasBeenPutBack = false;

		while(!s2.empty()){
			if(!hasBeenPutBack && temp > s2.top()) {
				s1.push(temp);
				hasBeenPutBack = true;
			}
			s1.push(s2.top());
			s2.pop();
		}
		if(!hasBeenPutBack) s1.push(temp);
	}
	return s1;
}

// Approach 2
// Similar to above, but we avoid putting the contents of s2 back in s1.
stack<int> sort2(stack<int>& s1){
	stack<int> s2;

	while(!s1.empty()){
		int temp = s1.top();
		s1.pop();
		while(!s2.empty() && temp < s2.top()){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(temp);
	}

	// Flip s2 into s1
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}

	return s1;
}

int main(){
	// Testing sort
	stack<int> s;
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(2);
	sort(s);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	// Testing sort2
	stack<int> s2;
	s2.push(3);
	s2.push(4);
	s2.push(1);
	s2.push(2);
	sort(s2);
	cout << s2.top() << endl;
	s2.pop();
	cout << s2.top() << endl;
	s2.pop();
	cout << s2.top() << endl;
	s2.pop();
	cout << s2.top() << endl;
	s2.pop();
}