// Breadth first search
#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

void BFS(Node* root, adjList* aL){
	queue<Node*> q;
	if(!root) return;

	// Setting all nodes to univisited
	for(int i = 0; i < NODES; i++){
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
	adjList* aL = new adjList;
	aL->addEdge(1, 4);
	aL->addEdge(1, 3);
	aL->addEdge(1, 2);
	aL->addEdge(2, 6);
	aL->addEdge(2, 5);
	aL->addEdge(4, 8);
	aL->addEdge(4, 7);
	aL->addEdge(6, 5);
	aL->addEdge(7, 1);
	aL->addEdge(7, 6);
	BFS(aL->ptrArray[0], aL);
}