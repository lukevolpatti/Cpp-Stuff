// Intersection
#include "LinkedList.h"
#include <unordered_map>

Node* intersection(Node* l1, Node* l2){
	Node* t1 = l1;
	Node* t2 = l2;
	unordered_map<Node*, bool> m;

	while(t1){
		m[t1] = true;
		t1 = t1->next;
	}

	while(t2){
		if(m[t2]) return t2;
		t2 = t2->next;
	}

	return NULL;
}

// Constant space solution: go through both lists and count number of nodes.
// Advance the start point of the longer one by the difference in nodes, then
// increment both pointers together until either they intersect or one reaches
// the end.

int main(){
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
	N3->next = NULL;
	N4->next = N2;
	Node* head = N1;
	Node* head2 = N4;
	cout << intersection(head, head2) << endl;
}