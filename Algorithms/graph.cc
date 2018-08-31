#include "graph.h"

ListNode::ListNode(int _vertexLabel, int _weight){
    vertexLabel = _vertexLabel;
    weight = _weight;
}

AdjNode::AdjNode(){
    visited = false;
}

void AdjList::addEdge(int start, int end, int weight){
    while(aL.size() <= max(start, end)){
        AdjNode aN;
        aL.push_back(aN);
    }
    ListNode newNode = ListNode(end, weight);
    aL[start].l.push_back(newNode);
}

