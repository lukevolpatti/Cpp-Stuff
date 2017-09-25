#include <iostream>
using namespace std;

struct Data{
	int data;
};

struct Node{
	Data d;
	Node* next;
};

struct Stack{
	Node* top;
	int currSize;
};

void initStack(Stack** sPtr){
	*sPtr = new Stack;

	(*sPtr)->currSize = 0;
	(*sPtr)->top = NULL;
}

void pop(Stack** sPtr, Data d1){
	if((*sPtr)->top == NULL) return;

	Node* temp = (*sPtr)->top;
	d1 = (*sPtr)->top->d;
	(*sPtr)->top = (*sPtr)->top->next;

	delete temp;
	(*sPtr)->currSize--;
}

void push(Stack** sPtr, int data){
	Node* newNode = new Node;
	
	newNode->d.data = data;
	newNode->next = (*sPtr)->top;
	(*sPtr)->top = newNode;

	(*sPtr)->currSize++;
}

void printAll(Stack* sPtr){
	Node* currNode = sPtr->top;
	cout << "The current size is: " << sPtr->currSize << endl;

	while(currNode != NULL){
		cout << currNode->d.data << endl;
		currNode = currNode->next;
	}
}


int main(){
	Stack* sPtr;
	Data d;
	initStack(&sPtr);
	printAll(sPtr);
	push(&sPtr, 10);
	push(&sPtr, 13);
	push(&sPtr, 5);
	push(&sPtr, 7);
	printAll(sPtr);
	pop(&sPtr, d);
	printAll(sPtr);
	pop(&sPtr, d);
	pop(&sPtr, d);
	pop(&sPtr, d);
	printAll(sPtr);
}