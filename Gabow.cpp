//
// Created by chloe on 01/06/18.
//

#include "Gabow.h"

Gabow::Gabow(const int n){
    count = 1;
    num = new int[n];
    inSCC = new bool[n];
    for (int i = 0; i < n; i++) {
        num[i] = 0;
        inSCC[i] = false;
    }
}

Gabow::~Gabow(){
    if(!S.empty()){
        S.pop();
    }
    if(!P.empty()){
        P.pop();
    }
    count = 0;
    delete num;
    delete inSCC;
    partition.clear();
}

void Gabow::printPartition(){
    std::cout<<"Gabow's algorithm"<<std::endl;
    for (std::vector<std::vector<int>>::iterator it = partition.begin(); it != partition.end(); it++) {
        std::cout <<"CFC :";
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout<<" "<<*it2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Gabow::parcours(Graph *g, const int s){
    num[s] = count;
    count++;

    S.push(s);
    P.push(s);

    std::vector<int> voisins = g->getNeighbors(s);
    for (std::vector<int>::iterator it = voisins.begin(); it != voisins.end(); it++) {
        if (num[*it] == 0){
            parcours(g, *it);
        }
        else if (!inSCC[*it]){
            while (num[P.top()] > num[*it]){
                P.pop();
            }
        }
    }
    if(P.top() == s){
        std::vector<int> scc;
        int i = -1;
        while( i != s) {
            scc.push_back(S.top());
            inSCC[S.top()] = true;
            i = S.top();
            S.pop();
        }
        P.pop();
        partition.push_back(scc);
    }
}

void Gabow::algorithm(Graph * g){
    for (auto i = 0; i < g->getNodeCount(); i++) {
        if (num[i] == 0){
            parcours(g, i);
        }
    }
}