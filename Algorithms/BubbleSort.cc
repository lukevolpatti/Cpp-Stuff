// Bubble sort
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v){
	bool swapped = true;
	while(swapped){
		swapped = false;
		for(int i = 0; i < v.size() - 1; i++){
			if(v[i] > v[i + 1]){
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				swapped = true;
			}
		}
	}
}

void printVec(vector<int>& v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
}

int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	printVec(v);
	bubbleSort(v);
	printVec(v);
}