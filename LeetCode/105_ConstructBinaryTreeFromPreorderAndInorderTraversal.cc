#include <iostream>
#include <vector>
using namespace std;

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preIndex, int inl, int inr){
	// preIndex is our root. We will find its left and right children. 
    TreeNode* newNode = new TreeNode(preorder[preIndex]);
    if(inl == inr) return newNode; // Base case

    // Finding the root in the inorder array.
    int i = inl;
    for(; i <= inr; i++) if(inorder[i] == preorder[preIndex]) break;

    // Check for left child
    preIndex++;
    if(preIndex < preorder.size()){
        for(int j = inl; j < i; j++){
            if(inorder[j] == preorder[preIndex]){ // Found a left child
                newNode->left = build(preorder, inorder, preIndex, inl, i-1);
                // Inorder array tells us how far ahead right child is in preorder array.
                preIndex += i-inl;
                break;
            }
        }
    }

    // Check for right child
    if(preIndex < preorder.size()){
        for(int j = i + 1; j <= inr; j++){
            if(inorder[j] == preorder[preIndex]){ // Found a right child
                newNode->right = build(preorder, inorder, preIndex, i+1, inr);
                break;
            }
        }
    }
    return newNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return NULL;
    return build(preorder, inorder, 0, 0, inorder.size() - 1);
}

int main(){

}