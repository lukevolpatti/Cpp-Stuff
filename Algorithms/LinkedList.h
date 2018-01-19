// Linked list implementation code
// Used to test CTCI solutions
// Struct implementation for faster testing
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node{
public:
	Node* next;
	int data;

	Node();
	Node(int d);
};

Node::Node(){
	data = 0;
	next = NULL;
}

Node::Node(int d){
	data = d;
	next = NULL;
}

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

void reverse(Node*& head){
	if(head == NULL) return;
	Node* prev = NULL;
	Node* curr = head;
	Node* next;

	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

#endif