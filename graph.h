#ifndef _HOKOKOK_GRAPH_
#define _HOKOKOK_GRAPH_ 1
#include <string>
#include <vector>

class Graph
{
private:
    int size;
    std::vector<std::vector<int>> adjMatrix;
public:
    Graph() : size(0) {};
    //~Graph();
    void LoadMatrix(std::string & filename);
    void PrintMatrix();
};

#endif