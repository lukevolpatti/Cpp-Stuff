// Triple step
#include <iostream>
#include <vector>
using namespace std;

// Bottom up recursive approach
int hop(int n){
    if(n == 1) return 1;
    if(n == 2) return 1 + hop(n - 1);
    if(n == 3) return 1 + hop(n - 1) + hop(n - 2);

    return hop(n - 1) + hop(n - 2) + hop(n - 3);
}

// Memoized DP approach
int hop2(int n, vector<int>& memo){
    // Alternative base case:
    // if(n < 0) return 0;
    // if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 1 + hop2(n - 1, memo);
    if(n == 3) return 1 + hop2(n - 1, memo) + hop2(n - 2, memo);

    if(memo[n] == 0) memo[n] = hop2(n - 1, memo) + hop2(n - 2, memo)
        + hop2(n - 3, memo);

    return memo[n];
}
int hop2(int n){
    vector<int> memo(n + 1, 0);
    return hop2(n, memo);
}

int main(){
    cout << hop(3) << endl;
    cout << hop(2) << endl;
    //cout << hop(100) << endl;
    cout << hop2(3) << endl;
    cout << hop2(2) << endl;
    cout << hop2(50) << endl;

}
