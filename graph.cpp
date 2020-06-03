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

    solution.resize(size);
    solution.clear();
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

void Graph::ShortestPath(int s)
{
    std::cout << "calculating : " << s << std::endl;

    std::vector<int> dist(adjMatrix[s]);
    std::vector<bool> found(size, false);
    std::vector<std::vector<int>> path(size, std::vector<int>(1, s));

    found[s] = true;

    for(int i = 0; i < size - 2; i++)
    {
        int cur;
        int mindist = 0x7FFFFFFF;
        for(int j = 0; j < size; j++)
            if(!found[j] && dist[j] <= mindist)
            {
                cur = j;
                mindist = dist[j];
            }
        found[cur] = true;
        path[cur].push_back(cur);

        for(int j = 0; j < size; j++)
            if(!found[j] && dist[cur] + adjMatrix[cur][j] < dist[j])
            {
                dist[j] = dist[cur] + adjMatrix[cur][j];
                path[j] = path[cur];
            }
    }

    for(int i = 0; i < size; i++)
    {
        solution[s][i].first = dist[i];
        solution[s][i].second = path[i];
    }

    std::cout << "complete : " << s << std::endl;
}

void Graph::PrintShortestPathWeight(int s)
{
    if(solution[s].size() == 0)
        this->ShortestPath(s);
    
    for(int i = 0; i < size; i++)
        std::cout << solution[s][i].first << std::endl;
}

void Graph::PrintShortestPath(int s)
{
    if(solution[s].size() == 0)
        this->ShortestPath(s);
    
    for(int i = 0; i < size; i++)
    {
        std::vector<int>::iterator iter;
        for(iter = solution[s][i].second.begin(); iter != solution[s][i].second.end(); iter++)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }
}