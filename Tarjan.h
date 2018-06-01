//
// Created by chloe on 01/06/18.
//

#ifndef PROJECT_GRAPHE_NEW_TARJAN_H
#define PROJECT_GRAPHE_NEW_TARJAN_H

#include <iostream>
#include <vector>
#include "Graph.h"

class Tarjan {
private:
    std::vector<std::vector<int>> partition;
    std::stack<int> S;
    int num, *accessibleNum, *nodeNum;
    bool *inS;

    void parcours(Graph * g, const int s);

public :
    Tarjan(const int n);
    ~Tarjan();

    void printPartition();
    void algorithm(Graph * g);

};


#endif //PROJECT_GRAPHE_NEW_TARJAN_H
