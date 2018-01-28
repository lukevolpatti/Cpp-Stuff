// Remove duplicat>es from sorted array
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    for(int i = 0; i < size - 1; i++){
        if(nums[i] == nums[i+1]) {
            nums.erase(nums.begin() + i);
            size = nums.size();
            i--;
        }
    }
    return nums.size();
}

int main(){
	
}