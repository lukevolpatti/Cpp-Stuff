#include <iostream>
#include <vector>
using namespace std;

// Do a level order traversal right to left. At the start of each level, simply
// add the first node in the level to the result vector.
// Alternative solution: use recursion. Keep track of the current level in the 
// tree - the size of the result should be the same. Basically, do a pre-order
// traversal, favouring right children over left.
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> result;
    if(!root) return result;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            TreeNode* temp = q.front();
            q.pop();
            if(i == 0) result.push_back(temp->val);
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
    }
    return result;
}

int main(){

}