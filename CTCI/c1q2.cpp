// Check permutation
#include <iostream>
#include <string>
using namespace std;

bool isPermutation(string s1, string s2){
	int a1[128] = {}; // Assume ASCII
	int a2[128] = {};

	for(int i = 0; i < s1.size(); i++) a1[s1[i]]++;
	for(int i = 0; i < s2.size(); i++) a2[s2[i]]++;

	for(int i = 0; i < 128; i++) if(a1[i] != a2[i]) return false;
	return true;
}

// Implementation that uses less space:
bool isPermutation2(string s1, string s2){
	int a[128] = {}; // Assume ASCII
	if(s1.size() != s2.size()) return false;

	for(int i = 0; i < s1.size(); i++){
		a[s1[i]]++;
		a[s2[i]]--;
	}

	for(int i = 0; i < 128; i++) if(a[i] != 0) return false;
	return true;
}


int main(){
	cout << isPermutation("aabbccdd", "abcdabcd") << endl;
	cout << isPermutation("aabbccdd", "abcdabc") << endl;
	cout << isPermutation2("aabbccdd", "abcdabcd") << endl;
	cout << isPermutation2("aabbccdd", "abcdabc") << endl;
}