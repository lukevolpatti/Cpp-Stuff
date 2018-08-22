#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPrefix(string s){
    vector<int> output(s.size());
    int j = 0;
    output[0] = 0;
    for(int i = 1; i < s.size(); i++){
        while(j > 0 && s[j] != s[i]) j = output[j - 1];
        if(s[i] == s[j]){
            output[i] = j + 1;
            j++;
        }
    }
    return output;
}

bool KMP(string text, string pattern){
    vector<int> prefix = getPrefix(pattern);
    int j = 0, i = 0;
    while(i < text.size() && j < pattern.size()){
    	if(text[i] == pattern[j]){
    		i++;
    		j++;
    	}
    	else{
    		if(j != 0) j = prefix[j - 1];
    		else i++;
    	}
    }
    return j == pattern.size();
}

int main(){
    vector<int> v = getPrefix("abcaby");
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    cout << KMP("abxabcabcaby", "abcaby") << endl;
}

