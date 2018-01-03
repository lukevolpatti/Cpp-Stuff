// Minimal Tree
#include <iostream>
#include "trees.h"
using namespace std;

Node* makeTree(int* v, int start, int end){
	int middle = start + (end + 1 - start)/2;

	Node* newNode = new Node(v[middle]);
	if(middle == start) return newNode;

	newNode->left = makeTree(v, start, middle - 1);
	newNode->right = makeTree(v, middle + 1, end);

	return newNode;
}

int main(){
	int v[] = {1,2,3,4,5,6,7};
	inOrder(makeTree(v, 0, 6));
}