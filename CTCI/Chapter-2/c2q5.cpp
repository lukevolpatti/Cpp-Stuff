// Sum list
#include "LinkedList.h"

// If nodes are stored in reverse order:
Node* sum(Node* head1, Node* head2){
	Node* newList = NULL;
	Node* l1 = head1;
	Node* l2 = head2;
	Node* newTail = NULL; // Keep track of tail of list for easy adding
	int carry = 0;

	while(l1 || l2 || carry){
		int sum = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;

		Node* newNode = new Node(sum % 10);

		if(!newList){
			newList = newNode;
			newTail = newList;
		}

		else {
			newTail->next = newNode;
			newTail = newTail->next;
		}

		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;

		carry = sum/10;
	}

	return newList;
}

// If nodes are stored in forward order:
// Option 1: reverse lists, then do as above
Node* sumForward(Node* head1, Node* head2){
	reverse(head1);
	reverse(head2);
	return sum(head1, head2);
}

// Option 2: construct vectors from each list and interate through the
// vectors backwards summing appropriately

int main(){
	// Tested and working on LeetCode

	// Some testing
	Node* N1 = new Node;
	Node* N2 = new Node;
	Node* N3 = new Node;
	Node* N4 = new Node;
	N1->data = 1;
	N2->data = 2;
	N3->data = 3;
	N4->data = 4;
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = NULL;
	Node* head = N1;
	printList(head);

	Node* N5 = new Node;
	Node* N6 = new Node;
	Node* N7 = new Node;
	Node* N8 = new Node;
	N5->data = 2;
	N6->data = 3;
	N7->data = 4;
	N8->data = 5;
	N5->next = N6;
	N6->next = N7;
	N7->next = N8;
	N8->next = NULL;
	Node* head2 = N5;
	printList(head2);
	printList(sumForward(head, head2));
}