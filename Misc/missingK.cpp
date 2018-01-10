// A sequence of numbers comtains all the integers 1 thru n, but one of them is
// missing. Find the missing integer k.
#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
int missingk(vector<int>& v){
	for(int i = 0; i < v.size() + 1; i++){
		bool found = false;
		for(int j = i; j < v.size(); j++){
			if(v[j] == i + 1) found = true; // could break here
		}
		if(!found) return i + 1;
	}
	return 0;
}

// O(n) time, O(n) space
int missingk2(vector<int>& v){
	vector<bool> found(v.size() + 1);
	for(int i = 0; i < v.size(); i++){
		found[v[i] - 1] = 1;
	}
	for(int i = 0; i < found.size(); i++){
		if(!found[i]) return i + 1;
	}
	return 0;
}

// O(n)
int missingk3(vector<int>& v){
	if(v[0] != 1) return 1;
	for(int i = 1; i < v.size(); i++){
		if(v[i] != v[i+1] - 1) return v[i] + 1;
	}
	return 0;
}

// O(n)
int missingk4(vector<int>& v){
	int idealSum = (v.size()+1)*(v.size() + 2)/2;
	int realSum = 0;

	for(int i = 0; i < v.size(); i++){
		realSum += v[i];
	}

	return idealSum - realSum;
}

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	cout << missingk(v) << endl;
	cout << missingk2(v) << endl;
	cout << missingk3(v) << endl;
	cout << missingk4(v) << endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	cout << missingk(v2) << endl;
	cout << missingk2(v2) << endl;
	cout << missingk3(v2) << endl;
	cout << missingk4(v2) << endl;
}