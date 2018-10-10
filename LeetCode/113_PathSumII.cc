#include <iostream>
#include <vector>
using namespace std;

void path(TreeNode* root, int target, int sum, vector<int>& v, vector<vector<int> >& res){
    if(!root) return;
    sum += root->val;
    v.push_back(root->val);
    if(!root->left && !root->right && sum == target){
        res.push_back(v);
        return;
    }
    if(root->left) {
        path(root->left, target, sum, v, res);
        v.pop_back();
    }
    if(root->right){
        path(root->right, target, sum, v, res);
        v.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> v;
    vector<vector<int> > res;
    path(root, sum, 0, v, res);
    return res;
}

int main(){
	
}