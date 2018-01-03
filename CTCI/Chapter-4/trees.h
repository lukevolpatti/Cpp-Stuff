// Trees header file
// Implementation and basic traversals. 
#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;

	Node();
	Node(int v);
	~Node();
};

Node::Node(){
	left = NULL;
	right = NULL;
}

Node::Node(int v){
	val = v;
	left = NULL;
	right = NULL;
}

Node::~Node(){
	if(left) delete left;
	if(right) delete right;
}

void preOrder(Node* root){
	if(!root) return;
	cout << root->val;
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node* root){
	if(!root) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val;
}

void inOrder(Node* root){
	if(!root) return;
	inOrder(root->left);
	cout << root->val;
	inOrder(root->right);
}