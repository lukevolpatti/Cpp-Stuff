// Return Kth to last
#include "LinkedList.h"

Node* kthLast(Node* head, int k){
	Node* runner = head;
	int totalNodes = 0;

	// Counting total number of nodes
	while(runner){
		totalNodes++;
		runner = runner->next;
	}

	runner = head;
	// Iterate through and decrement until kth last is reached
	// If kth last can't be reached, we end up returning NULL
	while(totalNodes != k && runner){
		runner = runner->next;
		totalNodes--;
	}

	return runner;
}

int main(){
	// Some testing
	// Tested for returning all positions in list
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
	cout << kthLast(head, 3)->data << endl;
}