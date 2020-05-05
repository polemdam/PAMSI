#include <stdlib.h>
#include <stdio.h>
#include "MatrixGraph.h"
#include "ListGraph.h"
using namespace std;



int main()
{

	int vertex[5] = {10, 50, 100, 500, 1000};
	double density[4] = {0.25, 0.5, 0.75, 1};

	test_for_Matrix(vertex, density,100);
	test_for_List(vertex,density,100);
	

	return 0;
}