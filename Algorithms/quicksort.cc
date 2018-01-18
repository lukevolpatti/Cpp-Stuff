// Quicksort
// Based on CLRS implementation.
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> & v, int m, int n){
	int pivot = v[n]; // This is the pivot. It is the last element.
	int i = m - 1; // Start i before the first element.
	for(int j = m; j < n; j++){ // Iterate right up to the last element.
		if(v[j] <= pivot){ // v[j] has to go in smaller half of array
			i = i + 1;
			// Swapping:
			int temp = v[j];
			v[j] = v[i];
			v[i] = temp;
		}
	}
	// Put the pivot in its spot:
	v[n] = v[i + 1];
	v[i + 1] = pivot;
	return i + 1; // Return the pivot index.
}

void quicksort(vector<int> & v, int m, int n){
	if(m < n){
		int q = partition(v, m, n);
		quicksort(v, m, q - 1);
		quicksort(v, q + 1, n);
	}
}


int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	quicksort(v, 0, 4);
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
}