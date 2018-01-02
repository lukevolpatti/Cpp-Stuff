// Breadth first search
#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

void BFS(Node* root, adjList* aL){
	queue<Node*> q;
	if(!root) return;

	// Setting all nodes to univisited
	for(int i = 0; i < aL->ptrArray.size(); i++){
		aL->ptrArray[i]->visited = 0;
	}
	
	q.push(root);
	root->visited = 1;

	while(!q.empty()){
		Node* curr = q.front();
		q.pop();
		cout << curr->vertexLabel << endl;
		Node* temp = aL->ptrArray[curr->vertexLabel - 1];
		while(temp){
			if(!temp->visited){ // only add unvisited nodes to the queue
				q.push(temp);
				temp->visited = true;
			}
			temp = temp->next;
		}
	}
}

int main(){

}