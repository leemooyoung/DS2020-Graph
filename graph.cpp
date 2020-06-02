#include "graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

void Graph::LoadMatrix(std::string & filename)
{
    std::fstream fs;
    fs.open(filename, std::ios_base::in);

    fs >> size;
    adjMatrix.resize(size, std::vector<int>(size));

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            fs >> adjMatrix[i][j];
}

void Graph::PrintMatrix()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            std::cout << adjMatrix[i][j] << " ";
        
        std::cout << std::endl;
    }
}

void Graph::PrintShortestPathWeight(int s)
{
    std::cout << "start" << std::endl;
    int * dist = new int[size];
    bool * found = new bool[size];

    std::copy(adjMatrix[s].begin(), adjMatrix[s].end(), dist);
    std::fill(found, found + size, false);
    found[s] = true;

    for(int i = 0; i < size - 2; i++)
    {
        int cur;
        int mindist = 0x7FFFFFFF;
        for(int j = 0; i < size; i++)
            if(!found[j] && dist[j] <= mindist)
            {
                cur = j;
                mindist = dist[j];
            }
        found[cur] = true;

        for(int j = 0; j < size; j++)
        {
            if(!found[j] && dist[cur] + adjMatrix[cur][j] < dist[j])
            {
                dist[j] = dist[cur] + adjMatrix[cur][j];
            }
        }
    }

    for(int i = 0; i < size; i++)
        std::cout << dist[i] << std::endl;
    
    //std::ostream_iterator<int, char> osi(std::cout, "\n");
    //std::copy(dist, dist + size, osi);

    delete[] dist;
    delete[] found;
}