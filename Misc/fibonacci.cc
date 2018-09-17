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

// Bottom-up dynamic programming
int fib3(int n){
    if(n == 0) return 0;
    int a = 0;
    int b = 1;
    for(int i = 1; i < n + 1; i++){
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    cout << fib1(5) << endl;
    //cout << fib1(50) << endl;
    cout << fib2(5) << endl;
    cout << fib2(5000) << endl;
    cout << fib3(5) << endl;
}
