#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
    void append(ListNode*& head, ListNode*& newNode){
        ListNode* temp = head;
        if(temp == NULL) {
            head = newNode;
            return;
        }
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = NULL;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL && l2 != NULL) {
                append(newHead, l2);
                l2 = l2 -> next;
            }
            else if(l1 != NULL && l2 == NULL){
                append(newHead, l1);
                l1 = l1 -> next;
            }
            else if(l1->val > l2->val){
                append(newHead, l2);
                l2 = l2->next;
            }
            else if(l1->val < l2->val){
                append(newHead, l1);
                l1 = l1->next;
            }
        }
        return newHead;
  }

  int main(){
    ListNode* L1 = NULL;
    ListNode* L2 = new ListNode(0);
    ListNode* res = mergeTwoLists(L1, L2);
    while(res!= NULL) {
        cout << res->val << endl;
        res = res->next;
    }
  }