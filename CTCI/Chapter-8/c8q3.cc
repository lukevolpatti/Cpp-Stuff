// Magic index
#include <iostream>
#include <vector>
using namespace std;

// When array elements are distinct and increasing, use binary search.
// O(log(n))
int search(int start, int end, vector<int>& v){
    int mid = (start+end)/2;
    if(mid == v[mid]) return mid;
    if(start == end) return -1; // No magic index

    if(v[mid] > mid) return search(start, mid, v);
    else return search(mid+1, end, v);
}

// When array elements are not distinct, use linear search
int search2(vector<int>& v){
    for(int i = 0; i < v.size(); i++)
        if(v[i] == i) return i;
    return -1;
}

int main(){
    vector<int> v = {0, 9, 10};
    cout << search(0, 2, v) << endl;
    vector<int> v2 = {-10, -2, 2};
    cout << search(0, 2, v2) << endl;
    vector<int> v3 = {1, 9, 10};
    cout << search(0, 2, v3) << endl;
    vector<int> v4 = {1, 9, 10, 11};
    cout << search(0, 3, v4) << endl;
    vector<int> v5 = {3, 4, 4, 4, 4};
    cout << search2(v5) << endl;
}
