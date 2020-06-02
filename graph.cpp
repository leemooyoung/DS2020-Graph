#include "graph.h"
#include <iostream>
#include <fstream>

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