//
// Created by chloe on 01/06/18.
//

#include "Tarjan.h"

//
//  Tarjan.cpp
//  Projet CFC : implémentation de 3 alogorithmes
//
//  Created by Chloé BENSOUSSAN on 02/05/2018.
//  Copyright © 2018 Chloé BENSOUSSAN. All rights reserved.
//

#include "Tarjan.h"
#include <algorithm>

Tarjan::Tarjan(const int n){
    num = 0;
    nodeNum = new int[n];
    accessibleNum = new int[n];
    inS = new bool[n];

    for (int i = 0; i < n; i++) {
        nodeNum[i] = -1;
        accessibleNum[i] = -1;
        inS[i] = false;
    }
}

Tarjan::~Tarjan(){
    num = 0;
    delete nodeNum;
    delete accessibleNum;
    delete inS;
    if(!S.empty()){
        S.pop();
    }
    partition.clear();
}

void Tarjan::printPartition() {
    std::cout<< "Tarjan's algorithm"<<std::endl;
    for (std::vector<std::vector<int>>::iterator it = partition.begin(); it != partition.end(); it++) {
        std::cout <<"CFC :";
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout<<" "<<*it2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Tarjan::parcours(Graph *g, const int s){
    nodeNum[s] = num;
    accessibleNum[s] = num;
    num++;

    S.push(s);
    inS[s] = true;

    //Parcours récursif
    std::vector<int> voisins = g->getNeighbors(s);
    for (std::vector<int>::iterator it = voisins.begin(); it != voisins.end(); it++) {
        if (nodeNum[*it] == -1){
            parcours(g, *it);
            accessibleNum[s] = std::min(accessibleNum[s], accessibleNum[*it]);
        }
        else if (inS[*it]){
            accessibleNum[s] = std::min(accessibleNum[s], nodeNum[*it]);
        }
    }

    //Vérification racine
    if (accessibleNum[s] == nodeNum[s]) {
        int sommet;
        std::vector<int> cfc;
        do{
            sommet = S.top();
            S.pop();
            inS[sommet] = false;
            cfc.push_back(sommet);
        } while(sommet != s);
        partition.push_back(cfc);
    }
}

void Tarjan::algorithm(Graph *g){
    for (int i = 0; i < g->getNodeCount(); i++) {
        if (nodeNum[i] == -1){
            parcours(g, i);
        }
    }
}