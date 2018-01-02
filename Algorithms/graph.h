#ifndef GRAPH_H
#define GRAPH_H
#define NODES 8

class Node{
public:
	bool visited;
	int vertexLabel;
	Node* next;
};

class adjList{
public:
	Node* ptrArray[NODES];
};

#endif