// Paint fill
#include <iostream>
#include <vector>
using namespace std;

// Perform a DFS. At each pixel, make sure the previous colour is the original colour.
// Then we know we should be filling the current pixel.
void colour(vector<vector<int> >&m, int new_colour, int orig_colour, int r, int c){
    if(m[r][c] != orig_colour) return;
    m[r][c] = new_colour;
    if(r > 0 && m[r-1][c] != new_colour) colour(m, new_colour, orig_colour, r-1, c);
    if(r < m.size() -1  && m[r+1][c] != new_colour) colour(m, new_colour, orig_colour, r+1, c);
    if(c > 0 && m[r][c-1] != new_colour) colour(m, new_colour, orig_colour, r, c-1);
    if(c < m[0].size() - 1 && m[r][c+1] != new_colour) colour(m, new_colour, orig_colour, r, c+1);
}

int main(){
    vector<vector<int> > v = { { 0, 2, 1, 0},
                               { 0, 0, 0, 0},
                               { 1, 1, 1, 0},
                               { 0, 0, 0, 0} };

    cout << "Before: " << endl;
    for(int i=0;i<v.size();i++)for(int j=0;j<v[0].size();j++){
        cout << v[i][j] << " ";
        if(j == v[0].size()-1) cout << endl;
    }
    cout << "After: " << endl;
    colour(v, 3, v[0][0], 0, 0);
    for(int i=0;i<v.size();i++)for(int j=0;j<v[0].size();j++){
        cout << v[i][j] << " ";
        if(j == v[0].size()-1) cout << endl;
    }

}

