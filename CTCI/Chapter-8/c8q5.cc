// Recursive Multiply
#include <iostream>
#include <vector>
using namespace std;

// We are given two numbers to multiply. Split the smaller number in two, and
// recursively add the result of the multiplication function called on each
// half of the smaller number. Memoize the results for performance in cases
// where the smaller number is divisible by 2.
// In fact, there is one more optimization that can be made - get rid of
// memoization altogether, and just add the result of the recursive call to
// itself. Also add to this the bigger number in the case where the smaller 
// number is not divisible by 2. 
int mult(int a, int b, vector<int>& v){
    int smaller = min(a,b);
    int bigger = max(a,b);
    if(smaller == 0) return 0;
    if(smaller == 1) return bigger;

    int new_smaller = smaller > 1;
    return v[new_smaller] ? v[new_smaller] : mult(new_smaller, bigger, v) +
        (v[new_smaller] ? v[new_smaller] : mult(smaller - new_smaller, bigger, v));
}

int recursive_multiply(int a, int b){
    vector<int> v(min(a,b));
    return mult(a, b, v);
}

int main(){
    cout << recursive_multiply(8, 7) << endl;
}
