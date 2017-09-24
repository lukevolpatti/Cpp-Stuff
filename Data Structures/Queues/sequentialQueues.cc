#include <iostream>
using namespace std;
#define MaxQueueSize 10

struct Node{
	int data;
};

struct Queue{
	int currSize;
	int front;
	int rear;
	struct Node queueArray[MaxQueueSize];
};

bool isFull(Queue* qPtr){
	if(qPtr->currSize == MaxQueueSize){
		return true; 
	}
	return false;
}

bool isEmpty(Queue* qPtr){
	if(qPtr->currSize == 0){
		return true;
	}
	return false;
}

void initQueue(Queue** qPtr){
	*qPtr = new Queue;
	(*qPtr)->currSize = 0;
	(*qPtr)->front = 0;
	(*qPtr)->rear = 0;
}

void enqueue(int data, Queue* qPtr){
	if(isFull(qPtr)) return;

	qPtr->queueArray[qPtr->rear].data = data;
	qPtr->rear = (qPtr->rear + 1) % MaxQueueSize;
	qPtr->currSize++; 
}

void dequeue(Queue* qPtr){
	if(isEmpty(qPtr)) return;

	qPtr->front = (qPtr->front + 1) % MaxQueueSize;
	qPtr->currSize--;
}

void printAll(Queue* qPtr){
	int index = qPtr->front;
	cout << "Current queue size: " << qPtr->currSize << endl;
	while(index != qPtr->rear){
		cout << qPtr->queueArray[index].data << endl;
		index++;
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