cmake_minimum_required(VERSION 3.10)
project(Project_Graphe_new)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project_Graphe_new
        src/main.cpp
        src/Graph/Graph.cpp header/Graph.h
        src/Graph/List.cpp header/List.h
        src/Graph/Matrix.cpp header/Matrix.h
        src/algorithm/Kosaraju.cpp header/Kosaraju.h
        src/algorithm/Tarjan.cpp header/Tarjan.h
        src/algorithm/Gabow.cpp header/Gabow.h)