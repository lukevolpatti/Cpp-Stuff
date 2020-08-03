#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<vector<int>>& res, queue<TreeNode*>& q) {
    vector<int> level;
    int q_size = q.size();
    for(int i = 0; i < q_size; i++) {
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        level.push_back(q.front()->val);
        q.pop();
    }
    res.push_back(level);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if (!root) return res;
    q.push(root);
    while(q.size() != 0)
        helper(res, q);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
	
}