#include <iostream>
using namespace std;

template <class T1>
T1 GetMax(T1 a, T1 b){
    if(a > b) return a;
    return b;
}

// Need new template for every function
template <class T1>
T1 GetMin(T1 a, T1 b){
    if(a > b) return b;
    return a;
}

int main(){
    int a = 5;
    int b = 7;
    cout << GetMax<int>(a, b) << endl;
    cout << GetMin<int>(a, b) << endl;
}
