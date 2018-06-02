//
// Created by chloe on 01/06/18.
//

#ifndef PROJECT_GRAPHE_NEW_GRAPH_H
#define PROJECT_GRAPHE_NEW_GRAPH_H

#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    int nodeCount;
    bool *inS;

protected:
    int edgeCount;

public :
    Graph(const int n);
    ~Graph();

    int getNodeCount();
    int getEdgeCount();
    void initInS();
    std::stack<int> DFS(const int s);

    virtual void clearGraph() = 0;
    virtual void addEdge(const int t, const int h) = 0;
    virtual std::vector<int> getNeighbors(const int n) = 0;
    virtual Graph * tranpose() = 0;
    virtual void deleteNode(const int n) = 0;
    virtual void printGraph() = 0;

};


#endif //PROJECT_GRAPHE_NEW_GRAPH_H
