// String compression
#include <iostream>
#include <string>
using namespace std;

string compress(string s){
	string newString = "";
	char prev = ' ';
	int count = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == prev) count++;
		else{
			if(count){
				newString += prev;
				newString += to_string(count);
			}
			prev = s[i];
			count = 1;
		}
	}
	newString += prev;
	newString += to_string(count);

	return (s.size() > newString.size()) ? (newString) : (s);
}
// More efficient implementation: use a vector of strings and only compound
// into a complete string at the end to avoid continuously extending the string

int main(){
	cout << compress("aabcccccaaa") << endl;
	cout << compress("abcdefg") << endl;
}