#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> output;
    vector<string> letters;
    if(digits.empty()) return output;
    string local;
    letters.push_back("");
    letters.push_back("");
    letters.push_back("abc");
    letters.push_back("def");
    letters.push_back("ghi");
    letters.push_back("jkl");
    letters.push_back("mno");
    letters.push_back("pqrs");
    letters.push_back("tuv");
    letters.push_back("wxyz");

    backtrack(output, local, letters, 0, digits);
    return output;
}

void backtrack(vector<string>& output, string& local, vector<string>& letters, int index, string& digits){
    // Base case
    if(index == digits.size()){
        output.push_back(local);
    }
    for(int i = 0; i < letters[digits[index] - '0'].size(); i++){
        local.push_back(letters[digits[index] - '0'][i]);
        backtrack(output, local, letters, index + 1, digits);
        local.pop_back();
    }
}

int main(){
	
}