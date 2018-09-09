#include <vector>
using namespace std;

int maxSubArray(vector<int>& v) {
    if(v.size() == 0) return 0;
    int currSum = 0;
    int maxSum = v[0];

    for(int i = 0; i < v.size(); i++){
        currSum += v[i];
        if(currSum >= maxSum) maxSum = currSum;
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}

int main(){
	
}