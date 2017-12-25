#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
	Node* next;
	int data;
};

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

void printList(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

void removeDuplicates(Node* & head){
	Node* temp = head;
	unordered_map <int, bool> m;
	while(temp){
		m[temp->data] = true;
		temp = temp->next;
	}

	temp = head;
	Node* prev = NULL;
	while(temp){
		if(m[temp->data]) {
			m[temp->data] = false;
			prev = temp;
			temp = temp->next;
		}
		else {
			deleteNode(prev, temp);
			temp = prev->next;
		}
	}
}

// Alternative solution: use a runner node. Runtime: O(n^2)

int main(){
	// Some testing
	Node* N1 = new Node;
	Node* N2 = new Node;
	Node* N3 = new Node;
	Node* N4 = new Node;
	N1->data = 1;
	N2->data = 2;
	N3->data = 2;
	N4->data = 5;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = NULL;
	Node* head = N1;
	printList(head);
	removeDuplicates(head);
	printList(head);

	Node* N5 = new Node;
	Node* N6 = new Node;
	Node* N7 = new Node;
	Node* N8 = new Node;
	N5->data = 2;
	N6->data = 2;
	N7->data = 2;
	N8->data = 5;
	N5->next = N6;
	N6->next = N7;
	N7->next = N8;
	N8->next = NULL;
	head = N5;
	printList(head);
	removeDuplicates(head);
	printList(head);
}