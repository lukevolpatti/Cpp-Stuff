// Past interview question.
// Question is to basically implement a database, supporting the following
// commands:
// GET, SET, UNSET, NUMWITHVALUE, END, BEGIN, ROLLBACK, COMMIT
// Where BEGIN is kind of like initiating logging for the subsequent commands,
// ROLLBACK is like 'git reset --hard', and COMMIT is like 'git commit'.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Command {
public:
	string commandName;
	string name;
	int oldValue;
	bool oldValueWasNull;
	Command(string _commandName, string _name, int _oldValue, bool _oldValueWasNull);
};

Command::Command(string _commandName, string _name, int _oldValue, bool _oldValueWasNull){
	commandName = _commandName;
	name = _name;
	oldValue = _oldValue;
	oldValueWasNull = _oldValueWasNull;
}

class Database {
public:
	void Parse();

private:
	// Variables
	unordered_map<string, int> m; // Stores our key value pairs
	stack<Command> s; // Stack of commands for part 2.

	// Functionality
	void Set(string name, int value);
	void Get(string name);
	void Unset(string name);
	void Numwithvalue(int value);
	void Rollback();
	void Commit();

	void PushCommand(string commandName, string name, int oldValue, bool oldValueWasNull);
};

void Database::Parse(){
	string line;
	string command = ""; // This will determine which private function we will call
	string arg1 = ""; // First argument, if applicable
	string arg2 = ""; // Second argument, if applicable

	// Continue until the user sends an eof
	while(!cin.eof() && command != "END"){
		getline(cin, line);

		stringstream lineStream(line);
		lineStream >> command >> ws;
		lineStream >> arg1 >> ws;
		lineStream >> arg2 >> ws;
		if(command == "SET") Set(arg1, stoi(arg2)); // Need C++11 for this
		if(command == "GET") Get(arg1);
		if(command == "UNSET") Unset(arg1);
		if(command == "NUMWITHVALUE") Numwithvalue(stoi(arg1));
		if(command == "BEGIN"){
			Command b("BEGIN", "", 0, 0);
			s.push(b);
		}
		if(command == "ROLLBACK") Rollback();
		if(command == "COMMIT") Commit();
	}
}

void Database::Set(string name, int value){
	if(!s.empty()) {
		// Need to check if old value was NULL because hash table values are
		// 0 by default in C++.
		if(m.find(name) != m.end()) PushCommand("SET", name, m[name], false);
		else PushCommand("SET", name, 0, true);
	}
	m[name] = value;
}

void Database::Get(string name){
	if(m.find(name) == m.end()) cout << "NULL" << endl;
	else cout << m[name] << endl;
}

void Database::Unset(string name){
	if(!s.empty()) {
		// Need to check if old value was NULL because hash table values are
		// 0 by default in C++.
		if(m.find(name) != m.end()) PushCommand("UNSET", name, m[name], false);
		else PushCommand("UNSET", name, 0, true);
	}
	if(m.find(name) != m.end()) m.erase(name);
}

void Database::Numwithvalue(int value){
	int count = 0;
	for (auto it = m.begin(); it != m.end(); it++)
		if(it->second == value) count++;
	cout << count << endl;
}

void Database::Rollback(){
	while(s.top().commandName != "BEGIN"){
		Command temp = s.top();
		if(temp.commandName == "SET"){
			if(temp.oldValueWasNull) m.erase(temp.name);
			else m[temp.name] = temp.oldValue;
		}
		else if(temp.commandName == "UNSET"){
			if(temp.oldValueWasNull) m.erase(temp.name);
			else m[temp.name] = temp.oldValue;
		}
		s.pop();
	}
	if(s.top().commandName == "BEGIN") s.pop();
}

void Database::Commit(){
	while(s.top().commandName != "BEGIN") s.pop();
	if(s.top().commandName == "BEGIN") s.pop();
}

void Database::PushCommand(string commandName, string name, int oldValue, bool oldValueWasNull){
	Command c(commandName, name, oldValue, oldValueWasNull);
	s.push(c);
}

int main(){
	Database d;
	d.Parse();
	cout << "Database session ended" << endl;
}