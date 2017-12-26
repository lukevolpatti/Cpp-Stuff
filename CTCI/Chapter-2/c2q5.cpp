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

int main(){
	// Tested and working on LeetCode
}