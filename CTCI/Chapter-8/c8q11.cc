// Coin change
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

// Bottom up dynamic programming
int count_dp2(vector<int>& denoms, int amount){
    vector<vector<int> > dp(amount + 1, vector<int> (denoms.size()));
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < denoms.size(); j++){
            if(i - denoms[j] == 0) dp[i][j] = 1;
            else{
                int left, above;
                if(i - denoms[j] < 0) above = 0;
                else above = dp[i-denoms[j]][j];
                if(j == 0) left = 0;
                else left = dp[i][j-1];
                dp[i][j] = left + above;
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}

// Tested an working on LeetCode
int main(){
    int amount = 100;
    vector<int> denoms = {25, 10, 5, 1};
    cout << count(denoms, amount, 0) << endl;
    vector<vector<int> > dp(amount + 1, vector<int> (denoms.size()));
    cout << count_dp(denoms, amount, 0, dp) << endl;
    cout << count_dp2(denoms, amount) << endl;
}
