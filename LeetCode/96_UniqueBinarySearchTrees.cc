#include <iostream>
#include <vector>
using namespace std;

// Basic idea: call f(n) the number of structurally unique BSTs that store values 1...n
// There is a recurrence relation:
// f(n) = f(n-1)f(0) + f(n-2)f(1) + ... + f(1)f(n-2) + f(0)f(n-1)
// With base cases f(0) = 1, f(1) = 1

// Solution 1: bottom-up dynamic programming
int numTrees(int n) {
	vector<int> f(n + 1);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
	    for (int j = 0; j < i; j++) {
	        f[i] += f[j] * f[i - j - 1];
	    }
	}
	return f[n];
}

// Solution 2: top-down dynamic programming
void numTreesHelper(vector<int>& f, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int f_i;
        int f_n_i;
        if (f[i] != 0) f_i = f[i];
        if (f[n-i-1] == 0) numTreesHelper(f, n-1);
        f_n_i = f[n-i-1];
        sum += f_i * f_n_i;
    }
    f[n] = sum;
}
int numTrees2(int n) {
    vector<int> f(n + 1);
    f[0] = 1;
    f[1] = 1;
    numTreesHelper(f, n);
    return f[n];
}

int main() {

}