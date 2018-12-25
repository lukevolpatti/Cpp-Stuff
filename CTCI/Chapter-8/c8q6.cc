#include <iostream>
using namespace std;

/* Recursively:
1. Shift n-1 disks from start to spare
2. Shift one disk (base) from start to finish
3. Shift n-1 disks from spare to finish
*/
void towersOfHanoi(int start, int spare, int finish, int n){
	if(n == 1){
		cout << "Move disk from " << start << " to " << finish << endl;
		return;
	}

	towersOfHanoi(start, finish, spare, n - 1);
	cout << "Move disk from " << start << " to " << finish << endl;
	towersOfHanoi(spare, start, finish, n - 1);
}

void towers(int n){
	towersOfHanoi(1, 2, 3, n);
}

int main(){
	towers(3);
}