//
// Created by chloe on 01/06/18.
//

#ifndef PROJECT_GRAPHE_NEW_GABOW_H
#define PROJECT_GRAPHE_NEW_GABOW_H

#include <iostream>
#include <stack>
#include <vector>
#include "Graph.h"

class Gabow {
private:
    std::vector<std::vector<int>> partition;
    std::stack<int> S, P;
    int count, *num;
    bool *inSCC;

    void parcours(Graph * g, const int s);

public:
    Gabow(const int n);
    ~Gabow();

    void printPartition();
    void algorithm(Graph * g);

};


#endif //PROJECT_GRAPHE_NEW_GABOW_H
