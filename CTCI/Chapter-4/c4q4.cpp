// Check balanced
#include <iostream>
#include "trees.h"
using namespace std;

int height(Node* root){
	// Base case
	// We use 1 here so that we don't interfere with the special meaning we
	// give to 0 below. By having 0 indicate imbalance, we can store the return
	// value of this function in a boolean function.
	if(!root) return 1;

	int LHeight = height(root->left);
	int RHeight = height(root->right);

	// If either subtree is unbalanced, pass that information up.
	if(LHeight == 0 || RHeight == 0) return 0;

	// If the current node is balanced, pass the height up.
	if(abs(LHeight - RHeight) <= 1) 
		return (LHeight > RHeight) ? LHeight + 1 : RHeight + 1;

	// The current node is not balanced --> pass that info up.
	return 0;
}

// Can use a little helper function here if we want to return a boolean value
// Helper function can also help detect the NULL root case. 

int main(){
	// Tested and working on LeetCode
}