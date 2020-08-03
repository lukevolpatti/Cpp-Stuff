#include <iostream>
#include <vector>
using namespace std;

void get_score(int index, vector<int>& v, vector<int>& scores) {
    if (v[index] == -1) {
        scores[index] = 1;
        return;
    }
    int parent = v[index];
    if (scores[parent] == 0) 
        get_score(parent, v, scores);
    scores[index] = scores[parent] + 1;
}

int main(){
    vector<int> v {-1, 8, 6, 0, 7, 3, 8, 9, -1, 6};
    vector<int> scores(v.size(), 0);
    // Can create a bool array "visited", keeping track of which indices get_score
    // has been called on. Eliminates a bit of repetition. 

    for (int i = 0; i < v.size(); i++) {
        get_score(i, v, scores);
    }
    cout << *max_element(scores.begin(), scores.end()) << endl;
}
