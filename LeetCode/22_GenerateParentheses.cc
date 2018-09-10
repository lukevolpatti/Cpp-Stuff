#include <string>
#include <vector>
using namespace std;

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string local;
    backTrack(res, n, 0, local);
    return res;
}

void backTrack(vector<string>& res, int n, int open, string local){
    if(local.empty()) {
        local.push_back('(');
        open = 1;
    }
    if(local.size() == n*2) res.push_back(local);
    if((local.size() + open) < (n*2)){
        local.push_back('(');
        backTrack(res, n, open + 1, local);
        local.pop_back();
    }
    if(open){
        local.push_back(')');
        backTrack(res, n, open - 1, local);
        local.pop_back();
    }
}

int main(){

}