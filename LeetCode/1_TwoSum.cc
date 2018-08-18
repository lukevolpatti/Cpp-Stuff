#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ind(2);
    ind[0] = 0;
    ind[1] = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                ind[0] = i;
                ind[1] = j;
            }
        }
    }
    return ind;
}

int main(){
	
}