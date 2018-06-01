//
// Created by chloe on 01/06/18.
//

#ifndef PROJECT_GRAPHE_NEW_KOSARAJU_H
#define PROJECT_GRAPHE_NEW_KOSARAJU_H

#include "Graph.h"

class Kosaraju {
private:
    std::vector<std::vector<int>> partition;

public:
    Kosaraju();
    ~Kosaraju();

    void printPartition();
    void deleteNodeFromStack(std::stack<int> *S, const int n);
    void algorithm(Graph *g);
};


#endif //PROJECT_GRAPHE_NEW_KOSARAJU_H
