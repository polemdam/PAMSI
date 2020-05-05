#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

class Graph
{
protected:
    int V, E;
    float density;

public:
    const int &getV() const { return V; };
    const int &getE() const { return E; };

    Graph(){};
    virtual ~Graph(){};
    explicit Graph(int t_V, int t_E, double t_density) : V(t_V), E(t_E), density(t_density){};

    virtual void printGraph() const = 0;
    virtual void fillGraph() const = 0;
};