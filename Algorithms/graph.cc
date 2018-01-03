#include "graph.h"

adjList::adjList(){
	for(int i = 0; i < NODES; i++){
		Node* nullNode = NULL;
		ptrArray[i] = nullNode;
	}
}

void adjList::addEdge(int start, int end){
	// while(start > ptrArray.size() || end > ptrArray.size()){
	// 	ptrArray.push_back(NULL);
	// }

	Node* newNode = new Node(end);
	newNode->next = ptrArray[start - 1];
	ptrArray[start - 1] = newNode;
}