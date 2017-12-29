// Stack min
#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* minVal; // The min node of the stack BEFORE this node was added
};

struct MinStack {
	Node* top;
	Node* minNode;

	Stack();
	void push(Node* n);
	Node* pop();
	Node* min();
};

MinStack::MinStack(){
	top = NULL;
	minNode = NULL;
}

void MinStack::push(Node* n){
	if(!top){
		top = n;
		minNode = n;
		n->next = NULL;
		n->minVal = NULL;
	}
	else {
		n->next = top;
		top = n;
		n->minVal = minNode; // Min val before push
		// Will help us set minNode if this node is deleted
		if(n->data < minNode->data) minNode = n;
	}
}

Node* MinStack::pop(){
	if(!top) return NULL;
	Node* temp = top;
	top = top->next;
	minNode = temp->minVal;

	return temp;
}

Node* MinStack::min(){
	return minNode;
}

int main(){
	// Tested and working on LeetCode
}