#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    // Need to find the highest index k where nums[k] < nums[k + 1].
    // It's that k that we will swap later.
    int k, l;
    for(k = nums.size() - 2; k >= 0; k--) if(nums[k] < nums[k + 1]) break;
    if(k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    // Now, we need to find the largest l such that nums[l] > nums[k].
    // This way, we minimize how much we increase the number.
    for(l = nums.size() - 1; l > k; l--) if(nums[l] > nums[k]) break;
    
    // Swap
    swap(nums[k], nums[l]);
    
    // Reverse everything after k because these numbers are in descending
    // order (this is guaranteed in the first step of finding k).
    reverse(nums.begin() + k + 1, nums.end());
}

int main(){
	
}