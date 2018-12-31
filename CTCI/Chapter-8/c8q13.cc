// Stack of boxes
#include <iostream>
#include <vector>
using namespace std;

class Box {
public:
    int h;
    int w;
    int d;
    Box(int _h, int _w, int _d){
        h = _h;
        w = _w;
        d = _d;
    }
};

struct less_than_key{
    inline bool operator() (const Box& b1, const Box& b2){
        return (b1.w < b2.w);
    }
};

// Brute force, try all possibilities
int stackOfBoxes(vector<Box> boxes, int h_lim, int w_lim, int d_lim, int totalHeight){
    int max_height = totalHeight;
    for(int i = 0; i < boxes.size(); i++){
        Box b = boxes[i];
        if(b.h < h_lim && b.w < w_lim && b.d < d_lim){
            max_height = max(max_height, stackOfBoxes(boxes, b.h, b.w, b.d, totalHeight + b.h));
        }
    }
    return max_height;
}

// Sorted for efficiency
int stackOfBoxesSorted(vector<Box> boxes, int index, int h_lim, int w_lim, int d_lim, int totalHeight){
    int max_height = totalHeight;
    for(int i = index + 1; i < boxes.size(); i++){
        Box b = boxes[i];
        if(b.h < h_lim && b.w < w_lim && b.d < d_lim){
            max_height = max(max_height, stackOfBoxesSorted(boxes, index, b.h, b.w, b.d, totalHeight + b.h));
        }
    }
    return max_height;
}

int main(){
    vector<Box> b{ Box(4, 4, 4), Box( 3, 2, 1), Box(1, 2, 3), Box(5, 5, 5) };
    sort(b.rbegin(), b.rend(), less_than_key());
    cout << stackOfBoxesSorted(b, -1, 100, 100, 100, 0) << endl;
}
