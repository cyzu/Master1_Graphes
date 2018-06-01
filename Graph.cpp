//
// Created by chloe on 01/06/18.
//

#include "Graph.h"

Graph::Graph(const int n) {
    nodeCount = n;
}

Graph::~Graph() {

}

int Graph::getNodeCount() {
    return nodeCount;
}