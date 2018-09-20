#include <iostream>
using namespace std;

int reverse(int num) {
    int new_num = 0;

    bool is_negative = false;
    if(num < 0){
        is_negative = true;
        num = -1 * num;
    }

    while(num > 0){
        int temp = num % 10;
        num = num / 10;
        new_num *= 10;
        new_num += temp;
    }
    return is_negative ? -1 * new_num : new_num;
}

int main(){
	
}