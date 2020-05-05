#include "MatrixGraph.h"
#include <chrono>

static int infinity = 1000000;
static int neg_infinity = -1000000;
static int balance = -10;

MatrixGraph::MatrixGraph(int t_V, double t_density)
    : Graph(t_V, static_cast<int>(t_density * t_V * (t_V - 1)), t_density),
      matrix(std::make_unique<std::unique_ptr<int[]>[]>(t_V))
{

    for (int cell = 0; cell < V; ++cell)
    {

        matrix[cell] = std::make_unique<int[]>(t_V);
        for (int column = 0; column < V; ++column)
        {

            if (cell == column)
                matrix[cell][column] = 0;
            else
                matrix[cell][column] = infinity;
        }
    }
}
void MatrixGraph::printGraph() const
{

    std::cout << "\n  Matrix representation\n\n ";

    for (int i = 1; i <= V; ++i)
    {

        if (i <= 10)
            std::cout << i << ".   ";
        else if (i <= 100)
            std::cout << i << ".  ";
        else
            std::cout << i << ". ";
    }
    std::cout << "\n\n";
    for (int Row = 0; Row < V; Row++)
    {
        for (int Col = 0; Col < V; Col++)
        {
            if (matrix[Row][Col] < 10)
                std::cout << matrix[Row][Col] << "    ";

            else if (matrix[Row][Col] < 100)
                std::cout << matrix[Row][Col] << "   ";

            else
                std::cout << matrix[Row][Col] << "  ";
        }
        std::cout << "\n";
    }
}
void MatrixGraph::fillGraph() const
{

    if (density == 1)
    {
        for (int Row = 0; Row < V; ++Row)
        {
            for (int Col = 0; Col < V; ++Col)
            {
                if (Row != Col)
                {
                    int foo_weight = rand() % 20 + balance;
                    while (foo_weight == 0)
                    {

                        foo_weight = rand() % 20 + balance;
                    }
                    matrix[Row][Col] = foo_weight;
                }
            }
        }
    }
    else
    {
        int foo_edges = E;
        while (foo_edges)
        {

            int rowNode = rand() % V;
            int columnNode = rand() % V;

            if (matrix[rowNode][columnNode] == 0 || matrix[rowNode][columnNode] == 250)
            {

                int foo_weight = rand() % 20 + balance;
                while (foo_weight == 0)
                {

                    foo_weight = rand() % 20 + balance;
                }
                if (rowNode != columnNode)
                {

                    matrix[rowNode][columnNode] = foo_weight;
                    --foo_edges;
                }
            }
        }
    }
}
void printSolutionMatrix(std::string t_path[], int t_dist[], int t_n, int startNode)
{
    std::cout << "The starting node was -> " << startNode << "\n\n";

    for (int i = 0; i < t_n; ++i)
    {

        if (t_dist[i] == neg_infinity)
        {
            std::cout << i << "->"
                      << "-inf\n";
            ;
            continue;
        }
        else if (t_dist[i] == infinity || t_dist == 0)
        {
            std::cout << i << "->"
                      << "inf\n";
            continue;
        }
        else
            std::cout << i << "->" << t_dist[i];
        if (i < 10)
            std::cout << "   ";
        else if (i < 100)
            std::cout << "  ";
        else
            std::cout << " ";
        if ((t_dist[i] >= 100 && t_dist[i] < 1000) || (-100 > t_dist[i] && t_dist[i] <= -10))
            std::cout << " The shortest path: " << t_path[i] << i;
        else if (0 <= t_dist[i] && t_dist[i] < 10)
            std::cout << "   The shortest path: " << t_path[i] << i;
        else if ((t_dist[i] >= 10 && t_dist[i] < 100) || (-10 < t_dist[i] && t_dist[i] < 0))
            std::cout << "  The shortest path: " << t_path[i] << i;
        else
            std::cout << "The shortest path: " << t_path[i] << i;

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

double BellmanFord(std::shared_ptr<MatrixGraph> t_graph, int t_startNode, bool t_printSolution)
{

    std::string *Path = new std::string[t_graph->getV()];

    auto t_start = std::chrono::high_resolution_clock::now();

    int *Distance = new int[t_graph->getV()];

    for (int i = 0; i < t_graph->getV(); ++i)
    {

        Distance[i] = infinity;
    }

    Distance[t_startNode] = 0;

    for (int i = 1; i < t_graph->getV(); ++i)
    {
        for (int j = 0; j < t_graph->getV(); ++j)
        {
            for (int w = 0; w < t_graph->getV(); ++w)
            {

                int u = j;
                int v = w;
                int weight = t_graph->getWeight(j, w);
                if (Distance[u] + weight < Distance[v])
                {

                    Distance[v] = Distance[u] + weight;
                    if (t_printSolution)
                    {

                        Path[v].clear();
                        Path[v].append(Path[u] + std::to_string(u) + "->");
                    }
                }
            }
        }
    }
    for (int i = 1; i < t_graph->getV(); ++i)
    {
        for (int j = 0; j < t_graph->getV(); ++j)
        {
            for (int w = 0; w < t_graph->getV(); ++w)
            {

                int u = j;
                int v = w;
                int weight = t_graph->getWeight(j, w);
                if (Distance[u] + weight < Distance[v])
                {

                    if (Distance[u] > infinity / 2)
                        Distance[u] = infinity;
                    else if (weight == infinity)
                        continue;
                    else
                        Distance[v] = neg_infinity;
                }
                else if (Distance[u] > infinity / 2)
                    Distance[u] = infinity;
            }
        }
    }
    auto t_end = std::chrono::high_resolution_clock::now();

    if (t_printSolution)
        printSolutionMatrix(std::move(Path), std::move(Distance), t_graph->getV(), t_startNode);
    delete[] Distance;
    delete[] Path;
    return std::chrono::duration<double>(t_end - t_start).count();
}
void test_for_Matrix(int (&vertTab)[5], double (&densTab)[4], int loops)
{

    for (double density : densTab)
    {
        for (int vertices : vertTab)
        {
            double sum = 0;
            for (int i = 0; i < loops; ++i)
            {

                std::shared_ptr<MatrixGraph> graph = std::make_shared<MatrixGraph>(vertices, density);
                int startNode = rand() % vertices;

                graph->fillGraph();
                sum += BellmanFord(std::move(graph), startNode, true);
                std::cout << (i * 100 / loops) + 1 << "%"
                          << "\r" << std::flush;
            }
            std::cout << vertices << " VERTICES   "
                      << " DURATION: " << sum << std::endl;
        }
        std::cout << "\n"
                  << density << " DENISTY\n"
                  << std::endl;
    }
}