// Route between nodes
#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

bool route(Node* root, adjList* aL, Node* target){
	queue<Node*> q;
	if(!root || !target) return false;
	if(root == target) return true;
	root->visited = true;
	q.push(root);

	while(!q.empty()){
		Node* curr = q.front();
		if(curr == target) return true;

		Node* temp = aL->ptrArray[curr->vertexLabel - 1];
		while(temp){
			if(!temp->visited){
				q.push(temp);
				temp->visited = true;
			}
			temp = temp->next;
		}
	}
	return false;
}

int main(){

}