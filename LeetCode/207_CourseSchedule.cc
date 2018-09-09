#include <vector>
#include <unordered_map>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
    vector<int> degrees = get_degrees(graph);
    
    // go through each element
    for(int i = 0; i < numCourses; i++){
        int j = 0;
        for(; j < numCourses; j++) if(degrees[j] == 0) break; // we've found a node with 0 indegree
        if(j == numCourses) return false; // no nodes with 0 indegree
        degrees[j] = -1; // mark as visited
        for(auto neighbor : graph[j]) degrees[neighbor]--;
    }
    return true;
}

vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
    vector<unordered_set<int>> graph(numCourses);
    for(auto p : prerequisites) graph[p.first].insert(p.second);
    return graph;
}

vector<int> get_degrees(vector<unordered_set<int>>& graph){
    vector<int> degrees(graph.size());
    for(auto n : graph) for(auto i : n) degrees[i]++;
    return degrees;
}

int main(){
	
}