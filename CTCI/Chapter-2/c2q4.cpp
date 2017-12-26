// Partition
#include "LinkedList.h"

class newNode{
public:
	Node* head;
	Node* rear;
	void insertFront(Node* temp);
	void insertRear(Node* temp);
};

void newNode::insertFront(Node* temp){
	temp->next = head;
	head = temp;
}

void newNode::insertRear(Node* temp){
	temp->next = NULL;
	rear->next = temp;
	rear = temp;
}

Node* partition(Node* head, int part){
	if(!head || !head->next) return head;

	newNode N;
	N.head = head;
	head = head->next;
	N.head->next = NULL;
	N.rear = N.head;

	Node* temp = head;
	while(temp){
		// Need to keep track of what temp points to, because
		// we are going to remove temp from this list.
		Node* temp2 = temp->next;
		if(temp->data < part){
			N.insertFront(temp);
		}
		else{
			N.insertRear(temp);
		}
		temp = temp2;
	}

	return N.head; // Head of new linked list
}

int main(){
	// Some testing
	Node* N1 = new Node;
	Node* N2 = new Node;
	Node* N3 = new Node;
	Node* N4 = new Node;
	N1->data = 8;
	N2->data = 6;
	N3->data = 1;
	N4->data = 5;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = NULL;
	Node* head = N1;
	printList(head);
	printList(partition(head, 5));
}