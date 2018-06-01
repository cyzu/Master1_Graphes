//
// Created by chloe on 01/06/18.
//

#include "Graph.h"

Graph::Graph(const int n) {
    nodeCount = n;
    inS = new bool[nodeCount];
}

Graph::~Graph() {

}

int Graph::getNodeCount() {
    return nodeCount;
}

void Graph::initInS() {
    for (int i = 0; i < nodeCount; i++) {
        inS[i] = false;
    }
}

std::stack<int> Graph::DFS(const int s){
    std::stack<int> result, S;

    S.push(s);
    inS[s] = true;

    while(!S.empty()){
        int x = S.top();
        S.pop();
        result.push(x);

        std::vector<int> voisins = getNeighbors(x);
        for (std::vector<int>::iterator it = voisins.begin(); it != voisins.end(); it++) {
            if (!inS[*it]){
                inS[*it] = true;
                S.push(*it);
            }
        }
    }
    return result;
}