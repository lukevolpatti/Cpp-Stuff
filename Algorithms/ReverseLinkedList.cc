// Reverse Linked List
#include <iostream>
using namespace std;

struct Node{
	Node* next;
	int data;
};

void reverse(Node*& head){
	Node* prev = NULL;
	Node* curr = head;
	Node* next = head;

	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

int main(){

}