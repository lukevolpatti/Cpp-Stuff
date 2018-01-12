// First common ancestor
#include <iostream>
#include "trees.h"
using namespace std;

bool inSubtree(Node* root, Node* N){
	if(!root) return 0;
	if(N == root) return 1;
	return inSubtree(root->left, N) || inSubtree(root->right, N);
}

Node* ancestor(Node* root, Node* N1, Node* N2){
	if(root == N1 || root == N2) return root;

	bool N1onLeft = inSubtree(root->left, N1);
	bool N2onLeft = inSubtree(root->left, N2);

	if(N1onLeft != N2onLeft) return root;
	Node* newRoot = N1onLeft ? root->left : root->right;
	return ancestor(newRoot, N1, N2);
}

int main(){
	// Tested and working on LeetCode
}