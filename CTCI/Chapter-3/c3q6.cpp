// Animal shelter
#include <iostream>
#include <string>
using namespace std;

// Node that stores animal type and id
struct Node{
	string animal; // dog or cat
	int id;
	Node* next;

	Node(string _animal, int _id);
};

Node::Node(string _animal, int _id){
	animal = _animal;
	id = _id;
	next = NULL;
}


// Class to house entire data structure
class LinkedList{
private:
	Node* front;
	Node* rear;

public:
	LinkedList();
	void enqueue(string _animal, int _id);
	int dequeueDog();
	int dequeueCat();
	int dequeueAny();
};

LinkedList::LinkedList(){
	front = NULL;
	rear = NULL;
}

void LinkedList::enqueue(string _animal, int _id){
	Node* n = new Node(_animal, _id);

	if(!front){
		front = n;
		rear = n;
	}
	else rear->next = n;
	rear = n;
}

int LinkedList::dequeueDog(){
	if(!front) return -1;

	Node* prev = NULL;
	Node* curr = front;
	int id;

	while(curr != NULL && curr->animal != "dog"){
		prev = curr;
		curr = curr->next;
	}

	if(!curr) return -1;

	if(!prev){
		if(front == rear){
			front = NULL;
			rear = NULL;
		}
		else front = front->next;
	}

	else prev->next = curr->next;

	id = curr->id;
	delete curr;
	return id;
}

int LinkedList::dequeueCat(){
	if(!front) return -1;

	Node* prev = NULL;
	Node* curr = front;
	int id;

	while(curr != NULL && curr->animal != "cat"){
		prev = curr;
		curr = curr->next;
	}

	if(!curr) return -1;

	if(!prev){
		if(front == rear){
			front = NULL;
			rear = NULL;
		}
		else front = front->next;
	}
	
	else prev->next = curr->next;

	id = curr->id;
	delete curr;
	return id;
}

int LinkedList::dequeueAny(){
	if(!front) return -1;

	Node* temp = front;
	int id = front->id;

	if(front == rear){
		front = NULL;
		rear = NULL;
	}
	else{
		front = front->next;
	}
	delete temp;
	return id;

}

int main(){
	LinkedList l;
	l.enqueue("cat", 1234);
	cout << l.dequeueAny() << endl;
	l.enqueue("cat", 1234);
	cout << l.dequeueCat() << endl;
	l.enqueue("cat", 1234);
	cout << l.dequeueDog() << endl;
	l.enqueue("cat", 1234);
	l.enqueue("dog", 2212);
	l.enqueue("cat", 1989);
	l.enqueue("dog", 2758);
	cout << l.dequeueAny() << endl;
	cout << l.dequeueCat() << endl;
	cout << l.dequeueCat() << endl;
	cout << l.dequeueDog() << endl;
	cout << l.dequeueDog() << endl;
	cout << l.dequeueDog() << endl;
}