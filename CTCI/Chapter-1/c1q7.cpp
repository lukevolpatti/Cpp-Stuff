// Rotate matrix
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > rotate(vector< vector<int> > &M){
	for(int i = 0; i < M.size()/2; i++){
		for(int j = i; j < M.size() - i - 1; j++){
			int temp = M[i][j];
			M[i][j] = M[M.size() - 1 - j][i];
			M[M.size() - 1 - j][i] = M[M.size() - 1 - i][M.size() - 1 - j];
			M[M.size() - 1 - i][M.size() - 1 - j] = M[j][M.size() - 1 - i];
			M[j][M.size() - 1 - i] = temp;
		}
	}
	return M;
}

int main(){
	// Tested and working on LeetCode
}
