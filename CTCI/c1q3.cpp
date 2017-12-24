// URLify
#include <iostream>
#include <string>
using namespace std;

// Assume that the number of spaces at the end of the list corresponds with the
// Number of spaces interspersed in the list. If this assumption is not valid,
// then we would simply have to make an initial pass over the string to count
// the number of embedded spaces.
string URLify(string s){
	int offset = 0;
	int i = s.size() - 1;

	// Counting the number of spaces at the end of the string
	while(s[i] == ' '){
		i--;
		offset++;
	}

	for(int i = s.size() - 1 - offset; i >= 0; i--){
		if(s[i] == ' '){
			s[i + offset] = '0';
			s[i + offset - 1] = '2'; 
			s[i + offset - 2] = '%';
			offset = offset - 2;
		}
		else{
			s[i + offset] = s[i];
		}
	}
	return s;
}

int main(){
	cout << URLify("Mr John Smith    ") << endl;
}