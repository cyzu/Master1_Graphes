# Makefile du projet de théorie des graphes
# author : Chloe Bensoussan
#
# M1 IFI, semestre 2 Juin 2018
# Univesrité Nice Sophia-Antipolis

SHELL = /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++11 -Wall
RM = rm -f

SRC_DIR	= src
GRAPH_DIR	= src/Graph
ALGO_DIR = src/algorithm
HEADER = -I./include

CPPFILES = main.cpp Graph.cpp List.cpp Matrix.cpp Gabow.cpp Kosaraju.cpp Tarjan.cpp
EXEC = graphe

OBJECTS := $(CPPFILES:%.cpp=%.o)

.PHONY : all clean

%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$*.cpp
%.o : $(GRAPH_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(GRAPH_DIR)/$*.cpp
%.o : $(ALGO_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(ALGO_DIR)/$*.cpp

all :: $(EXEC)

$(EXEC) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean ::
	$(RM) *.o $(EXEC)
