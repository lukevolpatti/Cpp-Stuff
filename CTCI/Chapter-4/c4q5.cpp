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

// Constant space solution (if recursion is ignored)
// Assume definition of BST is all left nodes smaller, all right nodes bigger.
int isBST(Node* head, bool isLeftChild){
    int left;
    int right; 
        
    if(!head->left && !head->right) return head->val;

    if(head->left) {
        left = isBST(head->left, true);
        if(left == INT_MIN) return INT_MIN;
        if(left >= head->val) return INT_MIN;
    }
    if(head->right) {
        right = isBST(head->right, false);
        if(right == INT_MIN) return INT_MIN;
        if(right <= head->val) return INT_MIN;
    }

    if(isLeftChild){
        if(!head->left && !head->right) return head->val;
        if(!head->right) return head->val;
        if(!head->left) return right;
        return right;
    }

    if(!isLeftChild){
        if(!head->left && !head->right) return head->val;
        if(!head->left) return head->val;
        if(!head->right) return left;
        return left;
    }
}

bool isValidBST(Node* head){
    if(!head) return true;
    if(isBST(head, true) != INT_MIN) return true;
    return false;
}

bool checkBST(Node* head){
	if(!head) return true;
	if(isBST(head, true) != INT_MIN) return true;
	return false;
}

int main(){
	// Tested and working on LeetCode
}