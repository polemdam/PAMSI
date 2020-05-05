#pragma once
#include <cstdlib>
#include <memory>
#include "Graph.h"

class MatrixGraph : public Graph
{
	std::unique_ptr<std::unique_ptr<int[]>[]> matrix;

public:
	explicit MatrixGraph(int t_V, double t_density);
	MatrixGraph() : Graph(){};
	void fillGraph() const override;
	void printGraph() const override;
	const int &getWeight(int row, int column) const { return matrix[row][column]; }
};
double BellmanFord(std::shared_ptr<MatrixGraph> t_graph, int t_startNode, bool t_printSolution);
void test_for_Matrix(int (&vertTab)[5], double (&densTab)[4], int loops);
void printSolutionMatrix(std::string t_path[], int t_dist[], int t_n, int startNode); 
