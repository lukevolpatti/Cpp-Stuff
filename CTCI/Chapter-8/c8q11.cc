#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Naive recursive solution
int count(vector<int>& denoms, int amount, int index){
    if(amount == 0) return 1;
    
    int ways = 0;
    for(int i = 0; index < denoms.size() && amount - i*denoms[index]>=0; i++)
        ways += count(denoms, amount - i*denoms[index], index + 1);
    return ways;
}

// Top down dynamic programming
int count_dp(vector<int>& denoms, int amount, int index, vector<vector<int> >& dp){
    if(dp[amount][index]) return dp[amount][index];
    if(amount == 0){
        //dp[amount][index] = 1;
        return 1;
    }
    
    int ways = 0;
    for(int i = 0; index < denoms.size() && amount - i*denoms[index]>=0; i++)
        ways += count_dp(denoms, amount - i*denoms[index], index + 1, dp);
    dp[amount][index] = ways;
    return ways;
}

// Tested an working on LeetCode
int main(){
    int amount = 5;
    vector<int> denoms = {5,2};
    cout << count(denoms, amount, 0) << endl;
    vector<vector<int> > dp(amount + 1, vector<int> (denoms.size()));
    cout << count_dp(denoms, amount, 0, dp) << endl;
}
