// Streams
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	cout << "Input a line of text: ";
	string line;
	getline(cin, line);
	stringstream stream(line);

	cout << stream.str() << endl;
	string temp;
	while(stream >> temp);
	cout << temp << endl;
	cout << stream.str() << endl; // Does not update, be careful!
	cout << stream.eof() << endl;
}