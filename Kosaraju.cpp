//
// Created by chloe on 01/06/18.
//

#include "Kosaraju.h"

Kosaraju::Kosaraju() {

}

void Kosaraju::printPartition() {
    for (std::vector<std::vector<int>>::iterator it = partition.begin(); it != partition.end(); it++) {
        std::cout <<"CFC :";
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout<<" "<<*it2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Kosaraju::deleteNodeFromStack(std::stack<int> *S, const int n){
    std::stack<int> tmp;
    while(!S->empty()){
        if (S->top() != n){
            tmp.push(S->top());
        }
        S->pop();
    }
    while(!tmp.empty()){
        S->push(tmp.top());
        tmp.pop();
    }
}

void Kosaraju::algorithm(Graph *g) {
    std::stack<int> S;
    bool inS[g->getNodeCount()];
    for (int i = 0; i < g->getNodeCount(); i++) {
        inS[i] = false;
    }
    g->initInS();
    while (S.size() < g->getNodeCount()){
        int node = 0;
        while (inS[node]){
            node++;
        }
        std::stack<int> result = g->DFS(node);
        while (!result.empty()){
            int x = result.top();
            result.pop();
            S.push(x);
            inS[x] = true;
        }
    }

    Graph * gTransposed = g->tranpose();
    gTransposed->initInS();

    while (!S.empty()){
        int x = S.top();
        S.pop();

        std::stack<int> result = gTransposed->DFS(x);

        std::vector<int> scc;
        while(!result.empty()){
            inS[result.top()] = false;
            scc.push_back(result.top());
            gTransposed->deleteNode(result.top());
            deleteNodeFromStack(&S, result.top());
            result.pop();
        }
        partition.push_back(scc);
    }
}