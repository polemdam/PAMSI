#pragma once
#include <cstdlib>
#include <memory>
#include "Graph.h"

struct Edge
{
    int source, dest, weight;
};

class ListGraph : public Graph
{

    Edge *edge;

public:
    ListGraph() : Graph(){};
    ~ListGraph() { delete[] edge; }

    explicit ListGraph(int t_V, double t_density)
        : Graph(t_V, static_cast<int>(t_density * t_V * (t_V - 1)), t_density),
          edge(new Edge[static_cast<int>(t_density * t_V * (t_V - 1))]) {}

    void fillGraph() const override;
    void printGraph() const override;

    const Edge *getEdge() const { return edge; }
    void addEdge(int guardNumber, int number, int weight, int flag) const;
    bool IfExist(int guardNumber, int nodeNumber) const;
};
double BellmanFord_1(std::shared_ptr<ListGraph> t_graph, int t_startNode, bool t_printSolution);
void test_for_List(int (&vertTab)[5], double (&densTab)[4], int loops);
void printSolutionList(std::string t_path[], int dist[], int t_n, int startNode); 