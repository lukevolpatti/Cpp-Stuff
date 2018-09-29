#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    return search(0, nums.size() - 1, nums);
}
int search(int start, int end, vector<int>& nums){
    int m = (start + end)/2;
    if((m == 0 && nums[m] <= nums[nums.size() - 1]) || (nums[m] <= nums[m-1]))
        return nums[m];
    if(m !=0 && nums[m - 1] < nums[end])
        return search(start, m-1, nums);
    else
        return search(m+1, end, nums);
}

int main(){
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	cout << findMin(v) << endl;
}