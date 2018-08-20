#include <iostream>
using namespace std;

struct CompareDist {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b) const noexcept
    { return a.first > b.first; }
};

// Alternative solution: throw everything into the priority queue right off the bat.
// Then there is no need to keep track of current position in each list.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* outputListStart = NULL;
        ListNode* curr = NULL;
        priority_queue<pair<int,int>,vector<pair<int,int>>, CompareDist> q;
        
        // Building up the priority queue
        for(int i = 0; i < lists.size(); i++){
            pair<int, int> val;
            if(lists[i] != NULL){
                val.first = lists[i]->val;
                val.second = i;
                q.push(val);
            }
        }
        
        while(q.size() > 0){
            pair<int, int> temp = q.top(); // <value, listFrom>
            q.pop();
            ListNode* tempNode = lists[temp.second];
            lists[temp.second] = lists[temp.second]->next;
            
            // Add the new node from the newly advanced list
            if(lists[temp.second] != NULL){
                pair<int, int> newNode;
                newNode.first = lists[temp.second]->val;
                newNode.second = temp.second;
                q.push(newNode);
            }
            
            // Add the node we just popped to the output list
            if(!outputListStart) {
                outputListStart = tempNode;
                curr = outputListStart;
                curr->next = NULL;
            }
            else{
                curr->next = tempNode;
                curr = curr->next;
            }
        }
        return outputListStart;
    }
};

int main(){

}