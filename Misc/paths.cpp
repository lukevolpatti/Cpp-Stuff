// Number of paths
// Given an nxm grid, compute the number of differents paths one can take to
// get from the top right corner to the bottom right corner of the grid.
// Assume that one can only move down or to the right. 
#include <iostream>
using namespace std;

int paths(int n, int m, int x, int y){
	if(x == n || y == m) return 1;
	return paths(n, m, x + 1, y) + paths(n, m, x, y+1);
}

int main(){
	cout << paths(3,2,1,1) << endl;
}