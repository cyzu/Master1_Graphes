//
// Created by chloe on 01/06/18.
//

#include "../../header/List.h"

List::List(const int n) : Graph(n) {
    neighbor = new std::set<int>[getNodeCount()];
}

void List::addEdge(const int t, const int h) {
    neighbor[t].insert(h);
}

int List::getNeighborCount(const int n) {
    return (int) neighbor[n].size();
}

/*std::stack<int> List::DFS(const int s) {
    std::stack<int> result, S;
    bool mark[getNodeCount()];
    for (int i = 0; i < getNodeCount(); i++) {
        mark[i] = false;
    }

    S.push(s);
    mark[s] = true;

    while(!S.empty()){
        int x = S.top();
        S.pop();
        result.push(x);

        std::vector<int> voisins = getNeighbors(x);
        for (std::vector<int>::iterator it = voisins.begin(); it != voisins.end(); it++) {
            if (!mark[*it]){
                mark[*it] = true;
                S.push(*it);
            }
        }
    }
    return result;
}*/

void List::printGraph() {
    for (int i = 0; i < getNodeCount(); i++){
        std::cout << "Sommet "<<i<<" ->";
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
