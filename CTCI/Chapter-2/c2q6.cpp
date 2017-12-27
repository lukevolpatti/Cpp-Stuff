// Palindrome
#include "LinkedList.h"
#include <vector>

// O(n) time and space solution
bool palindrome(Node* head){
	Node* temp = head;
	vector<int> v;

	// Constructing vector
	while(temp != NULL){
		v.push_back(temp->data);
		temp = temp->next;
	}

	// Checking if vector is palindrome
	int i = 0;
	while(i < v.size()/2){
		if(v[i] != v[v.size() - 1 - i]) return false;
		i++;
	}
	return true;
}

// Alternatives: do it recursively or use a stack

int main(){
	// Testing and working in LeetCode
}