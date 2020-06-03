#ifndef _HOKOKOK_GRAPH_
#define _HOKOKOK_GRAPH_ 1
#include <string>
#include <vector>

class Graph
{
private:
    int size;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<
        std::vector<
            std::pair<int, std::vector<int> >
        >
    > solution;
    void ShortestPath(int s);
public:
    Graph() : size(0) {}
    //~Graph();
    void LoadMatrix(std::string & filename);
    int GetSize() {return size;}
    void PrintMatrix();
    void PrintShortestPathWeight(int s);
    void PrintShortestPath(int s);
};

#endif