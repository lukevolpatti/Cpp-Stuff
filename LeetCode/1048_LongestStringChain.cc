#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() > second.size();
    }
};

int longestStrChain(vector<string>& words) {
    compare c;
    sort(words.begin(), words.end(), c);
    unordered_map<string, int> h;
    for (string w: words){
        h.emplace(w, 1);
    }
    
    for (int i = 0; i < words.size(); i++) {
        string w = words[i];
        for (int j = 0; j < w.size(); j++) {
            string w1 = w;
            w1.erase(j, 1);
            if (h.find(w1) != h.end())
                h.at(w1) = max(h.at(w1), h.at(w) + 1);
        }
    }
    auto x = std::max_element(h.begin(), h.end(),
    [](const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second; });
    return x->second;
}

int main() {
	
}