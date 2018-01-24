#include <iostream>
using namespace std;

Node* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	        //if( (p->val > root->val) && (q->val < root->val) || (p->val < root->val) && (q->val > root->val) ) return root;
	        
	        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor (root->left, p, q);
	        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor (root->right, p, q);
	        return root;
}

int main(){
	// Tested and working on LeetCode
}