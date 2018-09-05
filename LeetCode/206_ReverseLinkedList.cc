#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head) return head;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = head->next;
    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        if(nextNode) nextNode = nextNode->next;
    }
    return prev;
}

int main(){

}