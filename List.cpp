//
// Created by chloe on 01/06/18.
//

#include "List.h"

List::List(const int n) : Graph(n) {
    neighbor = new std::set<int>[getNodeCount()];
}

void List::addEdge(const int t, const int h) {
    neighbor[t].insert(h);
}

int List::getNeighborCount(const int n) {
    return (int) neighbor[n].size();
}

void List::DFS() {
//TODO DFS de Kosaraju
}

void List::printGraph() {
    for (int i = 0; i < getNodeCount(); i++){
        std::cout << "Sommet "<<i<<" ->";
        for (std::set<int>::iterator it = neighbor[i].begin(); it != neighbor[i].end(); it++) {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
}

std::vector<int> List::getNeighbors(const int n) {
    std::vector<int> succ;
    for (auto i = neighbor[n].begin(); i != neighbor[n].end() ; i++) {
        succ.push_back(*i);
    }
    return succ;
}

void List::tranpose(Graph * g){
    //TODO
};
