//
// Created by chloe on 01/06/18.
//

#ifndef PROJECT_GRAPHE_NEW_MATRIX_H
#define PROJECT_GRAPHE_NEW_MATRIX_H


#include "Graph.h"

class Matrix : public Graph {
public :
    int **matrix;

    Matrix(const int n);

    void addEdge(const int t, const int h) override;
    void printGraph() override;

    int getNeighborCount(const int n) override;
    std::vector<int> getNeighbors(const int n) override;

    Graph * tranpose();
    void DFS() override;
};


#endif //PROJECT_GRAPHE_NEW_MATRIX_H
