#include "graph.h"

void adjList::addEdge(int start, int end){
	while(start > v.size() || end > v.size()){
		v.push_back(NULL);
	}

	Node* newNode = new Node(end);
	newNode->next = v[start];
	v[start] = newNode;
}