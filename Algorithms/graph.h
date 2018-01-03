#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#define NODES 8
using namespace std;

class Node{
public:
	bool visited;
	int vertexLabel;
	Node* next;

	Node(){
		next = NULL;
		visited = false;
	}

	Node(int vertex){
		next = NULL;
		visited = false;
		vertexLabel = vertex;
	}
};

class adjList{
public:
	Node* ptrArray[NODES];

	adjList();
	void addEdge(int start, int end);
};

#endif