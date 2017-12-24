// Is unique
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Hash table implementation
bool isUnique(string s){
	unordered_map <char, int> m;

	for(int i = 0; i < s.size(); i++){
		if(m[s[i]]) return false;
		else m[s[i]]++;
	}
	return true;
}

// Array implementatio (assume ASCII)
bool isUniqueASCII(string s){
	bool a[128] = {};

	for(int i = 0; i < s.size(); i++){
		if(a[s[i]]) return false;
		else a[s[i]] = true;
	}
	return true;
}

// O(1) space solutions: 
//    compare all element pairs O(n^2)
//    sort string then step through O(nlogn)


int main(){
	cout << isUnique("absdgh") << endl;
	cout << isUnique("hello") << endl;
	cout << isUniqueASCII("absdgh") << endl;
	cout << isUniqueASCII("hello") << endl;
}