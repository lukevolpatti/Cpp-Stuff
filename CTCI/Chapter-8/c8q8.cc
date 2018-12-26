// Permutations with dups
#include <iostream>
#include <string>
#include <unordered_set>
#include <limits>
using namespace std;

// Make an unordered_set of the original string. Iterate through it. At each
// iteration, remove the current element and recurse down, passing down a
// 'so_far' string. When there's nothing left in the set, print what you have
// so far. 
void permutations(unordered_set<char>& s, string so_far){
    if(s.empty()) cout << so_far << endl;

    for(const auto& elem : s){
        so_far.push_back(elem);
        // Need to make a new set here. Can't modify the existing set because
        // that would invalidate the iterators. Tried this and got a seg fault.
        unordered_set<char> new_s;
        for(const auto& e : s) if(e != elem) new_s.insert(e);
        permutations(new_s, so_far);
        so_far.pop_back();
    }

}

void permutations_without_dups(string source){
    unordered_set<char> s;
    for(int i = 0; i < source.size(); i++) s.insert(source[i]);
    permutations(s, "");
}

int main(){
    permutations_without_dups("aaaaaabcd");
}
