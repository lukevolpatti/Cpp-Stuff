#include <iostream>
#include <vector>
using namespace std;

int count(vector<int>& denoms, int index, int amount){
    // Base case:
    if(index >= denoms.size() - 1) return 1;
    
    int num_solutions = 0;
    for(int i = 0; amount - i * denoms[index] >= 0; i++){
        int new_amount = amount - i * denoms[index];
        num_solutions += count(denoms, index + 1, new_amount);
    }
    return num_solutions;
}

int main(){
    vector<int> denoms = {25, 10, 5, 1};
    cout << count(denoms, 0, 100) << endl;
}
