// Merge sort
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int m, int r){
	int leftHalf = l;
	int rightHalf = m;
	vector<int> sorted;

	while(leftHalf < m && rightHalf <= r){
		if(v[leftHalf] < v[rightHalf]){
			sorted.push_back(v[leftHalf]);
			leftHalf++;
		}
		else{
			sorted.push_back(v[rightHalf]);
			rightHalf++;
		}
	}
	while(leftHalf < m){
		sorted.push_back(v[leftHalf]);
		leftHalf++;
	}
	while(rightHalf <= r){
		sorted.push_back(v[rightHalf]);
		rightHalf++;
	}

	for(int i = 0; i < sorted.size(); i++){
		v[l + i] = sorted[i];
	}

}

void mergeSort(vector<int>& v, int l, int r){
	if(l >= r ) return;
	int m = (l + r) / 2 + 1;
	mergeSort(v, l, m - 1);
	mergeSort(v, m, r);
	merge(v, l, m, r);
}

void print(vector<int>& v){
	for(int i = 0; i < v.size(); i ++) cout << v[i];
	cout << endl;
}

int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	print(v);
	mergeSort(v, 0, v.size() - 1);
	print(v);
}