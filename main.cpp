#include <iostream>
#include "List.h"
#include "Matrix.h"

void exemple1(Graph * g){
    /* 5 sommets
     * CFC 1 : a b c
     * CFC 2 : d
     * CFC 3 : e
     * */
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(1, 0);
    g->addEdge(0, 3);
    g->addEdge(3, 4);
}

void exemple2(Graph * g){
    /* 8 sommets
     * CFC 1 : a b e f
     * CFC 2 : c g
     * CFC 3 : d
     * CFC 4 : h
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
     * CFC 1 : a b c d
     * CFC 2 : e f
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
     * CFC 1 : a b c
     * CFC 2 : e d
     * CFC 3 : f g
     * CFC 4 : h
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
     * CFC 1 : a
     * CFC 2 : b e
     * CFC 3 : c f
     * CFC 4 : d
     * CFC 5 : g h i j k l
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
    Graph *g1 = new List(3);

    g1->addEdge(0,1);
    g1->addEdge(1,0);
    g1->addEdge(0,2);

    g1->printGraph();

    Graph *gt = g1->tranpose();
    gt->printGraph();
    return 0;
}