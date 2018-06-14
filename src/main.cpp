#include <iostream>
#include <fstream>
#include <sys/time.h>
#include "../header/List.h"
#include "../header/Matrix.h"
#include "../header/Kosaraju.h"
#include "../header/Tarjan.h"
#include "../header/Gabow.h"

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

void randomGraph(Graph * g, const int arete){
    /* Pour un nombre de sommet défini dans le constructeur,
     * on crée 'arete' aretes dans le graphe aléatoirement.
     * CFCs : faire confiance aux algos
     *
     * Il peut y avoir plusieurs fois les memes aretes*/

    for (int i = 0; i < arete; i++) {
        g->addEdge(std::rand()%g->getNodeCount(), std::rand()%g->getNodeCount());
    }
}


int main() {
    struct timeval debut, fin;
    srand(time(NULL));

    // ouverture en écriture à la fin du fichier
    std::ofstream f_Kosaraju;
    std::ofstream f_Tarjan;
    std::ofstream f_Gabow;
    f_Kosaraju.open("data_K.txt", std::ios::out | std::ios::trunc);
    f_Tarjan.open("data_T.txt", std::ios::out | std::ios::trunc);
    f_Gabow.open("data_G.txt", std::ios::out | std::ios::trunc);

    if (!f_Kosaraju.is_open() || !f_Tarjan.is_open() || !f_Gabow.is_open()){
        std::cerr << "Erreur ouverture des fichiers" << std::endl;
        exit(1);
    }

    Graph *g = new Matrix(100);
    //Graph *g = new List(1000);

    for (int arete = 0; arete <= 1000; arete+=10){
    //for (int arete = 0; arete <= 1000000; arete += 1000){}
        randomGraph(g, arete);

        /* KOSARAJU */
        gettimeofday(&debut, NULL);
        Kosaraju kosaraju;
        kosaraju.algorithm(g);
        gettimeofday(&fin, NULL);

        // affichage en microsecondes
        f_Kosaraju << g->getEdgeCount() << " " << ((fin.tv_sec * 1000000 + fin.tv_usec) - (debut.tv_sec * 1000000 + debut.tv_usec)) << std::endl;


        /* TARJAN */
        gettimeofday(&debut, NULL);
        Tarjan tarjan(g->getNodeCount());
        tarjan.algorithm(g);
        gettimeofday(&fin, NULL);

        f_Tarjan << g->getEdgeCount() << " " << ((fin.tv_sec * 1000000 + fin.tv_usec) - (debut.tv_sec * 1000000 + debut.tv_usec)) << std::endl;

        /* GABOW */
        gettimeofday(&debut, NULL);
        Gabow gabow(g->getNodeCount());
        gabow.algorithm(g);
        gettimeofday(&fin, NULL);

        f_Gabow << g->getEdgeCount() << " " << ((fin.tv_sec * 1000000 + fin.tv_usec) - (debut.tv_sec * 1000000 + debut.tv_usec)) << std::endl;

        g->clearGraph();
    }

    f_Kosaraju.close();
    f_Tarjan.close();
    f_Gabow.close();

    return 0;
}
