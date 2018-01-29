// Binary Tree Zigzag Level Order Traversal
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> Q;
    if(!root) return res;
    Q.push(root);
    bool left = 1;
    TreeNode* temp;
    
    while(!Q.empty()){
        int size = Q.size();
        vector<int> curr;
        for(int i = 0; i < size; i++){
            temp = Q.front();
            Q.pop();
            curr.push_back(temp->val);
            
            if(left){
                if(temp->right) Q.push(temp->right);
                if(temp->left) Q.push(temp->left);
            }
            else{
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
        }
        left = !left;
        res.push_back(curr);
    }
    return res;
}

int main(){
	
}