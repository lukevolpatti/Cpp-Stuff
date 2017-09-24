#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insertAtFront(int data, struct Node** head){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void insertAtEnd(int data, struct Node** head){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	Node* currNode = *head;

	if(currNode == NULL){
		insertAtFront(data, head);
	}
	else{
		while(currNode->next != NULL){
			currNode = currNode->next;
		}
		currNode->next = newNode;
	}
}

void printAll(struct Node* head){
	Node* currNode = head;
	while(currNode != NULL){
		cout << currNode->data << endl;
		currNode = currNode->next;
	}
}

void deleteNode(int data, Node** head){
	Node* temp = *head;
	Node* prevNode = NULL;
	while(temp!=NULL){
		if(temp->data == data){
			if(prevNode == NULL){
				*head = NULL;
			}
			else{
				prevNode->next = temp->next;
			}
			delete temp;
		}
		prevNode = temp;
		temp = temp->next;
	}
}

int main(void){
	Node* head = NULL; 
	insertAtFront(5, &head);
	insertAtFront(10, &head);
	insertAtEnd(3, &head);
	deleteNode(5, &head);


	printAll(head);
}