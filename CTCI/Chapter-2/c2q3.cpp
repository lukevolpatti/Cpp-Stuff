// Delete middle node
#include "LinkedList.h"

void deleteMiddleNode(Node* N){
	if(!N || !N->next) return;

	N->data = N->next->data;
	Node* temp = N->next;
	N->next = temp->next;
	delete temp;
}

int main(){
	
}