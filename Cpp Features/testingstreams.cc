#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s = "hello to one and all";
    stringstream myStream(s);
    
    myStream << "boop!";
    myStream << "hey";

    string temp;
    while(myStream >> temp){
        cout << temp << endl;
    }
}
