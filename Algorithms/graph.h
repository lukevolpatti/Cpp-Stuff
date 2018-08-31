#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
using namespace std;

class ListNode{
public:
    int vertexLabel;
    int weight;
    ListNode(int _vertexLabel = 0, int _weight = 0);
};

class AdjNode{
public:
    bool visited;
    list<ListNode> l;
    AdjNode();
};

class AdjList{
public:
    vector<AdjNode> aL;
    void addEdge(int start, int end, int weight = 0);
    void bfs(int start);
    void dfs(int start);
};

#endif
