#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Queue{
	int currSize;
	Node* front;
	Node* rear;
};

void initQueue(Queue** qPtr){
	*qPtr = new Queue;
	(*qPtr)->currSize = 0;
	(*qPtr)->front = NULL;
	(*qPtr)->rear = NULL;
}

void enqueue(int data, Queue* qPtr){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if(qPtr->rear == NULL){
		qPtr->rear = newNode;
		qPtr->front = newNode;
	}
	else{
		qPtr->rear->next = newNode;
		qPtr->rear = newNode;
	}
	qPtr->currSize++;
}

void dequeue(Queue* qPtr){
	if(qPtr->front == NULL){
		return;
	}

	Node* temp = qPtr->front;
	qPtr->front = qPtr->front->next;

	if(qPtr->front == NULL){
		qPtr->rear = qPtr->front;
	}

	delete temp;
	qPtr->currSize--;
}

void printAll(Queue* qPtr){
	Node* currNode = qPtr->front;
	cout << "Current queue size: " << qPtr->currSize << endl;
	while(currNode != NULL){
		cout << currNode->data << endl;
		currNode = currNode->next;
	}
}

int main(){
	Queue* qPtr;
	initQueue(&qPtr);
	enqueue(5, qPtr);
	printAll(qPtr);
	dequeue(qPtr);
	enqueue(10, qPtr);
	enqueue(2, qPtr);
	enqueue(3, qPtr);
	printAll(qPtr);
	dequeue(qPtr);
	printAll(qPtr);
	dequeue(qPtr);
	printAll(qPtr);
	dequeue(qPtr);
	printAll(qPtr);
}