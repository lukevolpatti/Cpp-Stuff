// Depth first search
#include "graph.h"
#include <iostream>
#include <stack>
using namespace std;

void DFS(Node* root, adjList* aL){
	stack<Node*> s;
	if(!root) return;

	// Setting all nodes to univisited
	for(int i = 0; i < aL->ptrArray.size(); i++){
		aL->ptrArray[i]->visited = 0;
	}

	s.push(root);
	root->visited = 1;

	while(!s.empty()){
		Node* curr = s.top();
		s.pop();
		cout << curr->vertexLabel << endl;
		Node* temp = aL->ptrArray[curr->vertexLabel - 1];
		while(temp){
			if(!temp->visited){ // only add unvisited nodes to the stack
				s.push(temp);
				temp->visited = true;
			}
			temp = temp->next;
		}
	}
}

void DFSrecursive(Node* root, adjList* aL){
	if(!root) return;
	if(root->visited) return;
	root->visited = true;
	cout << root->vertexLabel << endl;

	Node* temp = aL->ptrArray[root->vertexLabel - 1];
	while(temp){
		DFSrecursive(temp, aL);
		temp = temp->next;
	}
}

int main(){

}