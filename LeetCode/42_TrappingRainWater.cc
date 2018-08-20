#include <iostream>
#include <vector>
using namespace std;

// O(n) optimal solution
int trap(vector<int>& height){
    int totalWater = 0;
    int leftPos = 0;
    int rightPos = height.size() - 1;
    int maxLeft = 0;
    int maxRight = 0;
    while(leftPos <= rightPos){
        if(height[leftPos] <= height[rightPos]){
            if(maxLeft > height[leftPos]) totalWater += maxLeft - height[leftPos];
            else maxLeft = height[leftPos];
            leftPos++;
        }
        else{
            if(maxRight > height[rightPos]) totalWater += maxRight - height[rightPos];
            else maxRight = height[rightPos];
            rightPos--;
        }
    }
    return totalWater;
}

// O(n^2) brute force solution
int trap2(vector<int>& height) {
    int totalWater = 0;
    for(int i = 0; i < height.size(); i++){
        if(i != 0 && i != height.size() - 1){
            int maxLeft = height[i];
            int maxRight = height[i];
            for(int j = i; j >= 0; j--) if(height[j] > maxLeft) maxLeft = height[j];
            for(int k = i; k < height.size(); k++) if(height[k] > maxRight) maxRight = height[k];
            int maxLeftRight = min(maxLeft, maxRight);
            if(maxLeftRight > height[i]) totalWater += maxLeftRight - height[i];
        }
    }
    return totalWater;
}

int main(){
	
}