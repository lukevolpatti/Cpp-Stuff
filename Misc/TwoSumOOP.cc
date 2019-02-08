// Create a class that implments 2 methods:
// 1. accepts a number, and stores it
// 2. accepts a number, and returns true if that number is the sum of 2 of the previously stored numbers

// Example:
// twoSum.add(3)
// twoSum.add(2)
// twoSum.add(5)
// twoSum.add(11)
// twoSum.add(11)
// twoSum.isSum(5) => true
// twoSum.isSum(4) => false
// twoSum.isSum(22) => true
// twoSum.isSum(2) => false

// Requirements
// - duplicates
// - negatives
// - a legal isSum is the sum of exactly 2 elements

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum {
public:
  vector<int> twoSum_vec;
  unordered_map<int, int> twoSum_map;
  
  void add(int new_elem);
  bool isSum(int target);
};

void TwoSum::add(int new_elem){
  twoSum_vec.push_back(new_elem);
  twoSum_map[new_elem]++;
}

bool TwoSum::isSum(int target){
  for(unsigned i = 0; i < twoSum_vec.size(); i++){
    int complement = target - twoSum_vec[i];

    // See if complement is in hash map
    if(complement == twoSum_vec[i]){
      if(twoSum_map[complement] >= 2) return true;
    }
    else if(twoSum_map[complement] >= 1) return true;
  }
  
  return false;
}

int main(){
  TwoSum twoSum;
  twoSum.add(3);
  twoSum.add(-5);
  twoSum.add(2);
  twoSum.add(5);
  twoSum.add(11);
  twoSum.add(11);
  cout << twoSum.isSum(5) << endl; //=> true
  cout << twoSum.isSum(4) << endl; //=> false
  cout << twoSum.isSum(22) << endl; //=> true
  cout << twoSum.isSum(2) << endl; //=> false
  cout << twoSum.isSum(-2) << endl; //=> true
  cout << twoSum.isSum(-10) << endl; //=> false
}