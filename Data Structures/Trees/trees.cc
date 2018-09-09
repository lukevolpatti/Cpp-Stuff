// Trees
// Implementation and basic traversals.
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int val = 0; // Note: compile with C++11
    Node* left = NULL;
    Node* right = NULL;
};

void preOrder(Node* root){
    if(!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void levelOrder(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout << temp->val << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
    }
}

int main(){
    struct Node* n1 = new Node;
    struct Node* n2 = new Node;
    struct Node* n3 = new Node;
    struct Node* n4 = new Node;
    struct Node* n5 = new Node;
    struct Node* n6 = new Node;
    struct Node* n7 = new Node;
    struct Node* n8 = new Node;
    struct Node* n9 = new Node;

    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    n6->val = 6;
    n7->val = 7;
    n8->val = 8;
    n9->val = 9;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;
    n4->right = n9;

    preOrder(n1);
    cout << endl;
    inOrder(n1);
    cout << endl;
    postOrder(n1);
    cout << endl;
    levelOrder(n1);
    cout << endl;
}