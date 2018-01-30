// Quicksort
// Based on CLRS implementation.
#include <iostream>
#include <vector>
using namespace std;

// Partition will return the index of the element that has been put in its 
// proper place. 
int partition(vector<int>& v, int m, int n){
	int pivot = v[n]; // The last element will be the pivot.
					  // We will put it in its proper place.
	int i = m;
	int temp;
	for(int j = m; j < n; j++){
		if(v[j] <= pivot){
			// Do a swap and increment i
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;

			i++;
		}
	}

	// Now i is at the position of the first element in the array larger than
	// the pivot. So we'll swap v[i] and the pivot.
	v[n] = v[i];
	v[i] = pivot;
	return i; // Return the pivot index.
}

void quicksort(vector<int>& v, int m, int n){
	if(m < n){
		int q = partition(v, m, n);
		quicksort(v, m, q -1);
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