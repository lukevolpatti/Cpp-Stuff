// Word frequencies
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> countWords(){
	unordered_map<string, int> m;
	ifstream inFile;
	inFile.open("input.txt");
	string line;

	while(!inFile.eof()){
		getline(inFile, line);
		stringstream currLine(line);
		string word;
		while(currLine >> word){
			if(word[word.size() - 1] == '.' || word[word.size() - 1] == ',') word.pop_back();
			m[word]++;
		}
	}

	return m;
}
// Future fix: make it play nice with different types of punctuation.
// Only supports commas and periods at the moment. 

int main(){
	unordered_map<string, int> m = countWords();
	cout << m["poem"] << endl;
}