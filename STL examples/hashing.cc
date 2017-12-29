#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
	unordered_map<string, bool> attendance;
	attendance["james"] = true;
	attendance["michelle"] = true;
	attendance["rick"] = false;

	cout << attendance["james"] << endl;
	cout << attendance["michelle"] << endl;
	cout << attendance["rick"] << endl; 
	cout << attendance["jill"] << endl;
}