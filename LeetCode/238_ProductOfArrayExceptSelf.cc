#include <iostream>
#include <vector>
using namespace std;

vector<int> product_exclusion(vector<int>& v){
    if(v.size() == 0 || v.size() == 1) return v;
    
    int num_zeros = 0;
    int total_product = 1;
    vector<int> output;
    
    for(unsigned i = 0; i < v.size(); i++){
        if(v[i] == 0){
            if(num_zeros > 0){
                total_product = 0;
            }
            num_zeros++;
        }
        else{
            total_product *= v[i];
        }
    }
    for(unsigned i = 0; i < v.size(); i++){
        if(num_zeros >= 2) output.push_back(0);
        else if(num_zeros == 1){
            if(v[i] == 0) output.push_back(total_product);
            else output.push_back(0);
        }
        else{
            output.push_back(total_product / v[i]);
        }
    }
    
    return output;
}

int main(){

}