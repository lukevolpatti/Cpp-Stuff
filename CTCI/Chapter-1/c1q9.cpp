// String rotation
#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2){
	if(s1.size() != s2.size()) return false;
	return isSubstring(s1+s1, s2);
}

int main(){
	
}