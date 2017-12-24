// Zero matrix
#include <iostream>
#include <vector>
using namespace std;

void setZero(vector<vector<int> > & M){
	vector <int> rows(M.size(), 1);
	vector <int> cols(M[0].size(), 1);

	for(int i = 0; i < M.size(); i++){
		for(int j = 0; j < M[0].size(); j++){
			if(!M[i][j]){
				rows[i] = 0;
				cols[j] = 0;
			}
		}
	}

	for(int i = 0; i < M.size(); i++){
		for(int j = 0; j < M[0].size(); j++){
			if(!rows[i] || !cols[j]) M[i][j] = 0;
		}
	}
}

int main(){
	// Tested and working on LeetCode
}