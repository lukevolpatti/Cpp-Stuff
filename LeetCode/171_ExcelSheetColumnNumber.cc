// Excel sheet column number
#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s) {
    int sum;
    for(int i = 0; i < s.size(); i++) {
        if(i == s.size() - 1) sum += (s[i] - '@'); // assume ASCII
        else sum += (s[i] - '@') * 26 * (s.size() - i - 1);
    }
    return sum;
}

int main(){

}