// Number max
#include <iostream>
using namespace std;

int max(int a, int b){
	return (a/(a+b)) ? ((a >> 31) ? b : a) : ((a/b) ? ((a >> 31) ? b : a) : (b/(b+a)) ? a : b);
}

int main(){
	cout << max(-2, -1) << endl;
	cout << max(3, 4) << endl;
	cout << max(-2, 0) << endl;
	cout << max(0, -2) << endl;
}