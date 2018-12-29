#include <iostream>
#include <vector>
using namespace std;

int count_dp(vector<int>& denoms, int amount, int index, vector<vector<int> >& dp){
    if(dp[amount][index]) return dp[amount][index];
    if(amount == 0) return 1;
    
    int ways = 0;
    for(int i = 0; index < denoms.size() && amount - i*denoms[index]>=0; i++)
        ways += count_dp(denoms, amount - i*denoms[index], index + 1, dp);
    dp[amount][index] = ways;
    return ways;
}

int change(int amount, vector<int>& coins) {
    if(amount == 0 && coins.empty()) return 1;
    if(coins.empty()) return 0;
    sort(coins.rbegin(), coins.rend());
    vector<vector<int> > dp(amount + 1, vector<int> (coins.size()));
    return count_dp(coins, amount, 0, dp);
}

int main(){
	
}