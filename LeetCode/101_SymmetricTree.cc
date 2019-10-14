#include <iostream>
#include <vector>
using namespace std;

// Basic idea: do level-order traversal with vectors. At each level, chech for symmetry.
// Alternate solution: have two queues, one for the left branch from the root and one for the right.
// Do normal level order traversal on both of these, checking for equality when popping from the queue.
bool isSymmetric(TreeNode* root) {
    vector<TreeNode*> curr;
    curr.push_back(root);
    
    while(curr.size() != 0) {
        // make sure curr is good
        for (int i = 0; i < curr.size()/2; i++) {
            // only one is null --> not symmetric
            if ((curr[i] == NULL || curr[curr.size() - i - 1] == NULL) && curr[i] != curr[curr.size() - i - 1]) return false;
            // neither is null and values don't agree --> not symmetric
            if (curr[i] != curr[curr.size() - i - 1] && curr[i]->val != curr[curr.size() - i -1]->val) return false;
        }
        
        // populate new vector
        vector<TreeNode*> next;
        for(int i = 0; i < curr.size(); i++) {
            if (curr[i] != NULL) {
                next.push_back(curr[i]->left);
                next.push_back(curr[i]->right);
            }
        }
        curr = next;
    }
    
    return true;
}

int main() {

}