#include <iostream>
#include <vector>
#include "Graph.hpp"

namespace ariel {

    Graph::Graph() : numOfEdges(0), numOfVertices(0), adjacencyMatrix() {}

    void Graph::loadGraph(const std::vector<std::vector<int>> &matrix) {
        //check if the matrix is square
        size_t size_row= matrix.size(); //get the number of rows in the graph
        for (const auto& row : matrix) { // Iterate over each row in the graph
        if (row.size() != size_row) { // Check if the row size is not equal to the number of rows
            throw std::invalid_argument("Input graph is not a square matrix."); // Throw an exception if the graph is not square
        }
    } 
        numOfVertices = size_row;
        adjacencyMatrix = matrix;
        int numEdges = 0; // Initialize the number of edges to 0
        for (std::vector<std::vector<int>>::size_type i = 0; i < numOfVertices; ++i) { // Iterate over each row (or vertex)
        for (std::vector<int>::size_type j = 0; j < numOfVertices; ++j) { // Iterate over each column (or vertex)
            if (adjacencyMatrix[i][j] != 0) { // If there is an edge between vertex i and j
                ++numEdges; // Increment the number of edges
            }
        }      
    }
    numOfEdges=numEdges;
    }

    size_t Graph::getNumVertices(){
        return numOfVertices;
    }
    int Graph::getNumEdges(){
        return numOfEdges;
    }
    std::vector<std::vector<int>> Graph::getGraph() {
    return adjacencyMatrix;
    }
    void Graph::printGraph() {
        std::cout << "Graph with " << numOfVertices << " vertices and " << numOfEdges << " edges" << std::endl; //print the number of vertices and edges
    }

bool Graph::hasEdge(int from, int to) const {
    if (from < 0 || from >= static_cast<int>(adjacencyMatrix.size()) || to < 0 || to >= static_cast<int>(adjacencyMatrix.size())) {
        // Invalid vertex indices
        return false;
    }
    return adjacencyMatrix[static_cast<std::vector<std::vector<int>>::size_type>(from)][static_cast<std::vector<std::vector<int>>::size_type>(to)] != 0;
}
}