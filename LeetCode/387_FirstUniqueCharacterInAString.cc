#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> set;
    for(int i = 0; i < s.size(); i++) set[s[i]]++;
    for(int i = 0; i < s.size(); i++) if(set[s[i]] == 1) return i;
    return -1;
}

int main(){
	
}