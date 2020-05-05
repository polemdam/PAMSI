#include "ListGraph.h"
#include <chrono>

static int infinity = 1000000;
static int neg_infinity = -1000000;
static int balance = 0;

void ListGraph::addEdge(int guardNumber, int number, int t_weight, int flag) const
{

    edge[flag].dest = number;
    edge[flag].source = guardNumber;
    edge[flag].weight = t_weight;
}

bool ListGraph::IfExist(int guardNumber, int nodeNumber) const
{

    for (int Num = 0; Num < E; ++Num)
    {

        if (edge[Num].dest == nodeNumber && edge[Num].source == guardNumber)
            return true;
    }
    return false;
}

void ListGraph::fillGraph() const
{

    if (density == 1)
    {

        int foo = 0;
        for (int source = 0; source < V; ++source)
        {
            for (int dest = 0; dest < V; ++dest)
            {

                if (source != dest)
                {

                    int foo_weight = rand() % 20 + balance;
                    while (foo_weight == 0)
                    {

                        foo_weight = rand() % 20 + balance;
                    }
                    addEdge(source, dest, foo_weight, foo++);
                }
            }
        }
    }
    else
    {

        int foo_edges = 0;
        while (foo_edges < E)
        {

            int guardNode = rand() % V;
            int node = rand() % V;
            if (!IfExist(guardNode, node))
            {

                int foo_weight = rand() % 20 + balance;
                while (foo_weight == 0)
                {

                    foo_weight = rand() % 20 + balance;
                }

                if (guardNode != node)
                    addEdge(guardNode, node, foo_weight, foo_edges++);
            }
        }
    }
}

void ListGraph::printGraph() const
{
    std::cout << "\n List Representation\n\n";
    for (int source = 0; source < V; ++source)
    {
        std::cout << source;
        for (int iEdge = 0; iEdge < E; ++iEdge)
        {
            if (edge[iEdge].source == source)
                std::cout << "->"
                          << "(" << edge[iEdge].dest << "," << edge[iEdge].weight << ")";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void printSolutionList(std::string t_path[], int dist[], int t_n, int startNode)
{

    std::cout << std::string(20, '-') << "\n   FinalSolution\n\n";
    std::cout << "The starting node was -> " << startNode << "\n\n";

    for (int i = 0; i < t_n; ++i)
    {

        if (dist[i] == neg_infinity)
        {
            std::cout << i << "->"
                      << "-inf\n";
            continue;
        }
        else if (dist[i] == infinity || dist == 0)
        {
            std::cout << i << "->"
                      << "inf\n";
            continue;
        }
        else
        {
            std::cout << i << "->" << dist[i];
        }

        if (i < 10)
        {
            std::cout << "   ";
        }
        else if (i < 100)
        {
            std::cout << "  ";
        }
        else
        {
            std::cout << " ";
        }

        if ((dist[i] >= 100 && dist[i] < 1000) || (-100 > dist[i] && dist[i] <= -10))
        {

            std::cout << " The shortest path: " << t_path[i] << i;
        }
        else if (0 <= dist[i] && dist[i] < 10)
        {

            std::cout << "   The shortest path: " << t_path[i] << i;
        }
        else if ((dist[i] >= 10 && dist[i] < 100) || (-10 < dist[i] && dist[i] < 0))
        {

            std::cout << "  The shortest path: " << t_path[i] << i;
        }
        else
        {

            std::cout << "The shortest path: " << t_path[i] << i;
        }
        std::cout << std::endl;
    }
}

double BellmanFord_1(std::shared_ptr<ListGraph> t_graph, int startNode, bool t_printSolution)
{

    std::string *path = new std::string[t_graph->getV()];

    auto t_start = std::chrono::high_resolution_clock::now();

    int *distance = new int[t_graph->getV()];

    for (int iCell = 0; iCell < t_graph->getV(); ++iCell)
    {

        distance[iCell] = infinity;
    }

    distance[startNode] = 0;

    for (int i = 1; i < t_graph->getV(); ++i)
    {
        for (int j = 0; j < t_graph->getE(); ++j)
        {

            int u = t_graph->getEdge()[j].source;
            int v = t_graph->getEdge()[j].dest;
            int weight = t_graph->getEdge()[j].weight;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;

                if (t_printSolution)
                {
                    path[v].clear();
                    path[v].append(path[u] + std::to_string(u) + "->");
                }
            }
        }
    }
    for (int i = 1; i < t_graph->getV(); ++i)
    {
        for (int j = 0; j < t_graph->getE(); ++j)
        {
            int u = t_graph->getEdge()[j].source;
            int v = t_graph->getEdge()[j].dest;
            int weight = t_graph->getEdge()[j].weight;
            if (distance[u] + weight < distance[v])
            {

                if (distance[u] > infinity / 2)
                    distance[u] = infinity;
                else
                    distance[v] = neg_infinity;
            }
            else if (distance[u] > infinity / 2)
                distance[u] = infinity;
        }
    }
    auto t_end = std::chrono::high_resolution_clock::now();

    if (t_printSolution)
        printSolutionList(std::move(path), std::move(distance), t_graph->getV(), startNode);
    delete[] distance;
    delete[] path;
    return std::chrono::duration<double>(t_end - t_start).count();
}

void test_for_List(int (&vertTab)[5], double (&densTab)[4], int loops)
{
    for (double density : densTab)
    {
        for (int vertices : vertTab)
        {
            double sum = 0;
            for (int i = 0; i < loops; ++i)
            {
                std::shared_ptr<ListGraph> graph = std::make_shared<ListGraph>(vertices, density);
                int startNode = rand() % vertices;

                graph->fillGraph();

                sum += BellmanFord_1(std::move(graph), startNode, false);
                std::cout << (i * 100 / loops) + 1 << "%"
                          << "\r" << std::flush;
            }
            std::cout << vertices << " VERTICES   "
                      << "DURATION  " << sum << std::endl;
        }
        std::cout << "\n"
                  << density << " DENISTY\n"
                  << std::endl;
    }
}
