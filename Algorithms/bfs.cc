#include "graph.h"
#include <queue>
#include <iostream>

void AdjList::bfs(int start){
    if(start < 0 || start >= aL.size()) return;

    for(int i = 0; i < aL.size(); i++) aL[i].visited = false;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        if(currNode >= 0 && currNode < aL.size() && !aL[currNode].visited){
            for(list<ListNode>::iterator i = aL[currNode].l.begin();
                    i != aL[currNode].l.end(); i++) q.push(i->vertexLabel);
            aL[currNode].visited = true;
            cout << currNode << " ";
        }
    }
    cout << endl;
}

int main(){
    AdjList a1;
    a1.addEdge(0, 1);
    a1.addEdge(0, 2);
    a1.addEdge(0, 3);
    a1.addEdge(1, 4);
    a1.addEdge(1, 5);
    a1.bfs(0);
}
