#include <iostream>
using namespace std;

TreeNode* helper(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* node1 = helper(root->left);
    TreeNode* node2 = helper(root->right);
    TreeNode* root_right = root->right;
    if (root->left) {
        if (node1) {
            node1->right = root->right;
        }
        else root->left->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    if (node2) return node2;
    if (root_right) return root_right;
    if (node1) return node1;
    return root->right;
}
void flatten(TreeNode* root) {
    helper(root);
}

int main() {
	
}