#include <iostream>
#include <vector>
using namespace std;

// Iterate through the array. If the current element is larger than the next
// element, then we have a problem. We need to consider two possibilities -
// decreasing the current element, and increasing the next element. We decide
// what to do based on the previous element. 
// If we've already modified the array once and we run into another violation,
// then we can return 0 right away.
bool checkPossibility(vector<int>& nums) {
    bool seen_violation = 0;
    int prev = INT_MIN;
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i + 1]){
            if(seen_violation++) return 0;
            if(i == 0 || nums[i + 1] > prev) nums[i] = nums[i+1];
            else nums[i + 1] = nums[i];   
        }
        prev = nums[i];
    }
    return 1;
}

int main(){

}