// Linked list implementation code
// Used to test CTCI solutions
// Struct implementation for faster testing
#include <iostream>
using namespace std;

struct Node{
	Node* next;
	int data;
};

void printList(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

void deleteNode(Node* prev, Node* & temp){
	if(!prev){
		prev = temp;
		temp = temp->next;
		delete prev;
		return;
	}

	prev->next = temp->next;
	delete temp;
}