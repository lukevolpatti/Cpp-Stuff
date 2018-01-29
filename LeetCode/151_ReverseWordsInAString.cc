// Reverse words in a string
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void reverseWords(string &s){
    istringstream stream(s);
    string temp;
    stream >> s;
    while(stream >> temp) s = temp + " " + s;
    while(s[s.size()-1] == ' ') s.pop_back();
}

void reverseIndividualWord(string& s, int i, int j){
    j--; // j initially starts one position ahead.
    while(j > i){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void reverseWords2(string& s){
    // First reverse individual words, then reverse the whole string.
    int i = 0, j = 0;
    int size = s.size();
    while(i < size){
        while(i < size && s[i] == ' ') i++;
        if(i == size) break;
        j = i;
        while(j < size && s[j] != ' ') j++;
        reverseIndividualWord(s, i, j);
        i = j;
    }
    s.resize(j);
    reverseIndividualWord(s, 0, size);
}

int main(){
	string s = "    ";
	reverseWords2(s);
	cout << s << endl;
}