// Tic Tac Win
#include <iostream>
#include <vector>
#define SIZE 3
using namespace std;

// Not a full implementation of the tic tac toe game, just the algorithm to
// check for a win.

vector<int> rows(SIZE);
vector<int> cols(SIZE);
int diag = 0;
int antidiag = 0;

bool win(int x, int y, int player){
	if(player) {
		rows[x]++;
		cols[y]++;
		if(x == y) diag++;
		if(x + y + 1 == SIZE) antidiag++;
	}
	else{
		rows[x]--;
		cols[y]--;
		if(x == y) diag--;
		if(x + y + 1 == SIZE) antidiag--;
	}
	if(abs(rows[x]) == SIZE) return 1;
	if(abs(cols[y]) == SIZE) return 1;

	return 0;
}

int main(){

}