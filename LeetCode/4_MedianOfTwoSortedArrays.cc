#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int length1 = nums1.size();
    int length2 = nums2.size();
    if(length1 > length2) return findMedianSortedArrays(nums2, nums1);
    
    int start = 0;
    int end = length1;
    
    while(start <= end) {
        int mid1 = (start + end) / 2;
        int mid2 = (length1 + length2 + 1)/2 - mid1;
        
        int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int right1 = (mid1 == length1) ? INT_MAX : nums1[mid1];
        int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int right2 = (mid2 == length2) ? INT_MAX : nums2[mid2];
        
        if(left1 <= right2 && left2 <= right1){
            // Found the correct partition
            if((length1 + length2) % 2 == 0) return ((double)max(left1, left2) + min(right1, right2))/2;
            else return max(left1, left2);
        }
        else if(left1 > right2) end = mid1 - 1;
        else start = mid1 + 1;
    }
}

int main(){
	
}