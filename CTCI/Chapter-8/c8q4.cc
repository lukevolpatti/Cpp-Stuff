// Power Set
#include <iostream>
#include <vector>
using namespace std;

// Strategy: use backtracking. Iterate through the original vector starting from a given index.
// At each iteration, add the current element to a temp vector and add that temp vector to the
// final output vector. Then, call the same function recursively, with the start index
// incrememented by 1. Finally, pop the back of the vector; we want to undo the changes we made.
void powerset(vector<int>& original, vector<int>& temp, vector<vector<int> >& final, int index){
    for(int i = index; i < original.size(); i++){
        temp.push_back(original[i]);
        final.push_back(temp);
        powerset(original, temp, final, i+1);
        temp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > final;
    vector<int> temp;
    final.push_back(temp);
    powerset(nums, temp, final, 0);
    return final;
}


int main(){
	// Tested and working on leetcode
}