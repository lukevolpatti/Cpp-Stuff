// List of depths
#include <iostream>
#include <queue>
#include <list>
#include "trees.h"
using namespace std;

vector<list<Node*> > treeToLists(Node* root){
	vector<list<Node*> > v;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		list<Node*> t;
		v.push_back(t);
		Node* temp;
		int size = q.size();

		for(int i = 0; i < size; i++){
			temp = q.front();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
			q.pop();
			v[size - 1].push_front(temp);
		}
	}

	return v;
}

int main(){
	Node* N1 = new Node(2);
	Node* N2 = new Node(1);
	Node* N3 = new Node(3);
	N1->left = N2;
	N1->right = N3;
	vector<list<Node*> > v;
	v = treeToLists(N1);
	cout << v[0].front()->val;
	cout << v[1].front()->val;
	cout << v[1].back()->val;
}