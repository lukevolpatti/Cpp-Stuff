// Binary Search
// Return index of a specified element in a sorted array
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& v, int m, int n, int target){
	int q = (m + n)/2; // Middle index
	if(v[q] < target) return binarySearch(v, q + 1, n, target);
	if(v[q] > target) return binarySearch(v, m, q - 1, target);
	return q;
}

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(10);
	v.push_back(56);
	cout << binarySearch(v, 0, 5, 3) << endl;
}