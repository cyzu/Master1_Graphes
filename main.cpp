#include <iostream>
#include "List.h"
#include "Matrix.h"
#include "Kosaraju.h"
#include "Tarjan.h"

void exemple1(Graph * g){
    /* 5 sommets
     * CFC 1 : 0 1 2
     * CFC 2 : 3
     * CFC 3 : 4
     * */
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(1, 0);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
}

void exemple2(Graph * g){
    /* 8 sommets
     * CFC 1 : 0 1 4 5
     * CFC 2 : 2 6
     * CFC 3 : 3
     * CFC 4 : 7
     * */
    g->addEdge(0, 1);
    g->addEdge(4, 0);
    g->addEdge(0, 5);
    g->addEdge(1, 5);
    g->addEdge(5, 4);
    g->addEdge(1, 2);
    g->addEdge(5, 6);
    g->addEdge(6, 2);
    g->addEdge(2, 6);
    g->addEdge(2, 3);
    g->addEdge(7, 6);
}

void exemple3(Graph * g){
    /* 6 sommets (graphe non-connexe)
     * CFC 1 : 0 1 2 3
     * CFC 2 : 4 5
     * */
    g->addEdge(0, 1);
    g->addEdge(2, 0);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 3);
    g->addEdge(3, 2);
    g->addEdge(4, 5);
    g->addEdge(5, 4);
}

void exemple4(Graph * g){
    /* 8 sommets
     * CFC 1 : 0 1 2
     * CFC 2 : 4 3
     * CFC 3 : 5 6
     * CFC 4 : 7
     * */
    g->addEdge(1, 0);
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(3, 1);
    g->addEdge(5, 1);
    g->addEdge(3, 2);
    g->addEdge(4, 3);
    g->addEdge(3, 4);
    g->addEdge(4, 5);
    g->addEdge(6, 5);
    g->addEdge(5, 6);
    g->addEdge(7, 6);
    g->addEdge(7, 4);
    g->addEdge(7, 7);
}

void exemple5(Graph * g){
    /* 12 sommets
     * CFC 1 : 0
     * CFC 2 : 1 4
     * CFC 3 : 2 5
     * CFC 4 : 3
     * CFC 5 : 6 7 8 9 10 11
     * */
    g->addEdge(1, 0);
    g->addEdge(3, 1);
    g->addEdge(1, 4);
    g->addEdge(4, 1);
    g->addEdge(2, 1);
    g->addEdge(5, 4);
    g->addEdge(2, 5);
    g->addEdge(5, 2);
    g->addEdge(6, 4);
    g->addEdge(7, 5);
    g->addEdge(7, 6);
    g->addEdge(6, 8);
    g->addEdge(8, 9);
    g->addEdge(9, 6);
    g->addEdge(10, 7);
    g->addEdge(9, 11);
    g->addEdge(11, 10);
}

void exempleCircuit(Graph *g) {
    /* Nombre de sommet au choix
     * CFC1 : tous les sommets
     * */
    int index = g->getNodeCount()-1;
    for (int j = 0; j < index; j++) {
        g->addEdge(j, j+1);
    }
    if(index >=0){
        g->addEdge(index, 0);
    }
}

int main() {
    Graph *g1 = new List(8);
    exemple4(g1);

    g1->printGraph();

    Kosaraju kosaraju;
    kosaraju.algorithm(g1);
    kosaraju.printPartition();

    Tarjan tarjan(g1->getNodeCount());
    tarjan.algorithm(g1);
    tarjan.printPartition();
    return 0;
}