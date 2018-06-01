//
// Created by chloe on 01/06/18.
//

#include "Matrix.h"

Matrix::Matrix(const int n) : Graph(n) {
    matrix = new int*[getNodeCount()];

    for (int i = 0; i < getNodeCount(); i++) {
        matrix[i] = new int[getNodeCount()];
        for (int j = 0; j < getNodeCount(); j++) {
            matrix[i][j] = 0;
        }
    }
}

void Matrix::addEdge(const int t, const int h) {
    matrix[t][h] = 1;
}

int Matrix::getNeighborCount(const int n) {
    int count = 0;
    for (int i = 0; i < getNodeCount(); ++i) {
        count += matrix[n][i];
    }
    return count;
}

std::vector<int> Matrix::getNeighbors(const int n) {
    std::vector<int> neighbor;
    for (int i = 0; i < getNodeCount(); ++i) {
        if (matrix[n][i] == 1){
            neighbor.push_back(i);
        }
    }
    return neighbor;
}

void Matrix::DFS() {
    // TODO DFS pour matrice
}

void Matrix::printGraph() {
    std::cout<<" ";
    for (int i = 0; i < getNodeCount(); i++) {
        std::cout<<" "<<i;
    }
    std::cout<<std::endl;

    std::cout<<"  ";
    for (int i = 0; i < getNodeCount()*2 -1; i++) {
        std::cout<<"-";
    }
    std::cout<<std::endl;

    for (int i = 0; i < getNodeCount(); i++) {
        std::cout<<i<<"|";
        for (int j = 0; j < getNodeCount(); j++) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

Graph * Matrix::tranpose() {
    Matrix *tmp = new Matrix(getNodeCount());

    for (int i = 0; i < getNodeCount(); i++) {
        for (int j = 0; j < getNodeCount(); j++) {
            if (matrix[i][j] == 1){
                tmp->matrix[j][i] = 1;
            }
        }
    }
    return tmp;
}
