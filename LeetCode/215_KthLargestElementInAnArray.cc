#include <iostream>
#include <vector>
using namespace std;

// Sort, then access the kth largest number. O(nlog(n))
int findKthLargest(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int main() {

}