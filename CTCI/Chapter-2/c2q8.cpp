// Has cycle
#include "LinkedList.h"
using namespace std;

bool hasCycle(Node* head){
	if(!head || !head->next) return false;
	Node* walk = head;
	Node* run = head->next;

	while(run){
		if(walk == run) return true;
		if(run->next) run = run->next->next;
		else return false;
		walk = walk->next;
	}
	return false;
}

int main(){
	// Tested and working on LeetCode
}