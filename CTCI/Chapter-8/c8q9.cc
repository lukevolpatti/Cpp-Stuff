#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pass down a string containing what you have so far recursively. At each
// iteration, check to see if you can add an additional open/close bracket. If
// you can, do so and continue to recurse. If you can't, you're at the end and
// can print the string you're given.
void parens(int open, int closed, int n, string s){
    if(closed == n) cout << s << endl;

    if(open < n) parens(open+1, closed, n, s + '(');
    if(closed < open) parens(open, closed+1, n, s + ')');
}

int main(){
    parens(0, 0, 3, "");
}
