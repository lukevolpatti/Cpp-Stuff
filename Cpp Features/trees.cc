#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
    Node(Node* l, Node* r, int v);
};

Node::Node(Node* l, Node* r, int v){
    left = l;
    right = r;
    val = v;
}

void preorder(Node* n){
    if(!n) return;
    cout << n->val << endl;
    preorder(n->left);
    preorder(n->right);
}

int main(){
    Node* n1 = new Node(NULL, NULL, 5);
    Node* n2 = new Node(NULL, NULL, 10);
    Node* n3 = new Node(n1, n2, 7);
    preorder(n3);
}
