// One away
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool oneAway(string orig, string s){
	if(orig.size() == s.size()){ // Checking for one character edit
		bool hasBeenDifferent = false;
		for(int i = 0; i < s.size(); i++){
			if(orig[i] != s[i]){
				if(hasBeenDifferent) return false;
				hasBeenDifferent = true;
			}
		}
		return true;
	}

	else if(orig.size() - s.size() == 1){ // Check for deletion in s
		int offset = 0;
		for(int i = 0; i < s.size(); i++){
			if(offset > 1) return false;
			if(s[i] != orig[i + offset]) offset++;
		}
		return true;
	}

	else if(s.size() - orig.size() == 1){ // Check for deletion in s
		int offset = 0;
		for(int i = 0; i < orig.size(); i++){
			if(offset > 1) return false;
			if(orig[i] != s[i + offset]) offset++;
		}
		return true;
	}

	else return false;
}

int main(){
	cout << oneAway("pale", "ple") << endl;
	cout << oneAway("pales", "pale") << endl;
	cout << oneAway("pale", "bale") << endl;
	cout << oneAway("pale", "park") << endl;
	cout << oneAway("pale", "elap") << endl;
	cout << oneAway("pale", "bake") << endl;

}