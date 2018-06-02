//
// Created by chloe on 01/06/18.
//

#include "../../header/List.h"

List::List(const int n) : Graph(n) {
    neighbor = new std::set<int>[getNodeCount()];
}

void List::addEdge(const int t, const int h) {
    neighbor[t].insert(h);
    edgeCount++;
}

void List::printGraph() {
    for (int i = 0; i < getNodeCount(); i++){
        std::cout << "Node "<<i<<" ->";
        for (std::set<int>::iterator it = neighbor[i].begin(); it != neighbor[i].end(); it++) {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
    std::cout<<std::endl;
}

std::vector<int> List::getNeighbors(const int n) {
    std::vector<int> succ;
    for (auto i = neighbor[n].begin(); i != neighbor[n].end() ; i++) {
        succ.push_back(*i);
    }
    return succ;
}

Graph * List::tranpose(){
    List * tmp = new List(getNodeCount());
    for (int i = 0; i < getNodeCount(); i++) {
        for (std::set<int>::iterator it = neighbor[i].begin(); it != neighbor[i].end(); it++){
            tmp->neighbor[*it].insert(i);
        }
    }
    return tmp;
};

void List::deleteNode(const int n) {
    for (int i = 0; i < getNodeCount(); i++) {
        if (i == n){
            neighbor[i].clear();
        }
        else{
            neighbor[i].erase(n);
        }
    }
}

void List::clearGraph(){
    for (int i = 0; i < getNodeCount(); ++i) {
        neighbor[i].clear();
    }
    edgeCount = 0;
}
