//aseelzatmy3@gmail.com 324885417

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
using namespace std;
namespace ariel{
class Graph{
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        size_t numOfVertices;
        int numOfEdges;
    public:
        Graph();
        bool hasEdge(int from, int to) const; // Method to check if there is an edge between two vertices
        void loadGraph(const std::vector<std::vector<int>> &matrix);
        void printGraph();
        size_t getNumVertices();
        int getNumEdges();
        vector<vector<int>> getGraph();

};
}
#endif //GRAPH_H