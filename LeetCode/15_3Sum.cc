#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& v) {
    vector<vector<int>> output;
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        int l = i + 1;
        int r = v.size() - 1;
        if ((i>0) && (v[i]==v[i-1])) continue;
        while(l < r){
            if(v[i] + v[l] + v[r] == 0){
                // add to output
                vector<int> temp;
                temp.push_back(v[i]);
                temp.push_back(v[l]);
                temp.push_back(v[r]);
                output.push_back(temp);
                while(v[l] == v[l + 1]) l++;
                while(v[r] == v[r - 1]) r--;
                l++;
                r--;
            }
            else if(v[i] + v[l] + v[r] > 0) r--;
            else l++;
        }
    }
    return output;
}

int main(){
	
}