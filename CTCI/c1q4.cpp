// Palindrome permutation
#include <iostream>
#include <string>
using namespace std;

// Assume ascii
bool palindromePermutation(string s){
	int a[128] = {};
	bool hasBeenOdd = false;

	for(int i = 0; i < s.size(); i++) a[s[i]]++;
	for(int i = 0; i < 128; i++){
		if(a[i] % 2 == 1){
			if(hasBeenOdd) return false;
			else hasBeenOdd = true;
		}
	}
	return true;
}

int main(){
	cout << palindromePermutation("kayakee") << endl;
	cout << palindromePermutation("civqic") << endl;
}