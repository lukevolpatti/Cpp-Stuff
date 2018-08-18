#include <iostream>
#include <string>
using namespace std;

string licenseKeyFormatting(string S, int K) {
    string output = "";
    int position = 0;
    int firstNonDash = 0;
    while(S[firstNonDash] == '-'){
        firstNonDash++;
    }
    for(int i = S.size() - 1; i >=0; i--){
        if(S[i] != '-'){
            if(S[i] < 91){
                output += S[i];
            }
            else {
                output += (S[i] - 32);
            }
            position++;
            if(position >= K){
                position = 0;
                if(i != 0 && i != firstNonDash){
                    output += "-";
                }
            }
        }
    }
    reverse(output.begin(), output.end());
    return output;
}

int main(){
	
}