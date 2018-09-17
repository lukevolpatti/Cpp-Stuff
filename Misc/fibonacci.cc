#include <iostream>
#include <vector>
using namespace std;

// Normal recursion
int fib1(int n){
    if(n == 0 || n == 1) return 1;
    return fib1(n - 1) + fib1(n - 2);
}

// Memoized
int fib2(int n, vector<int>& memo){
    if(memo[n] == 0) memo[n] = fib2(n - 1, memo) + fib2(n - 2, memo);
    return memo[n];
}
int fib2(int n){
    vector<int> memo(n + 1, 0);
    memo[0] = 1;
    memo[1] = 1;
    return fib2(n, memo);
}


int main(){
    cout << fib1(5) << endl;
    //cout << fib1(50) << endl;
    cout << fib2(5) << endl;
    cout << fib2(5000) << endl;
}
