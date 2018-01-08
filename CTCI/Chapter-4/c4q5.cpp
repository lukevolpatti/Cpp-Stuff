// Validate BST
#include <iostream>
#include <vector>
#include "trees.h"
using namespace std;

void inOrder(vector<int>& v, Node* root){
	if(!root) return;
	inOrder(v, root->left);
	v.push_back(root->val);
	inOrder(v, root->right);
}

bool isBST(Node* root){
	vector<int> v;
	inOrder(v, root);
	int prev = 0;
	if(v.size()) prev = v[0];

	for(int i = 0; i < v.size(); i++){
		if(v[i] < prev) return 0;
		prev = v[i];
	}

	return 1;
}

int main(){
	// Tested and working on LeetCode
}