//aseelzatmy3@gmail.com 324885417

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test a connected graph
    ariel::Graph connectedGraph;
    vector<vector<int>> connectedGraphData = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    connectedGraph.loadGraph(connectedGraphData);
    CHECK(ariel::Algorithms::isConnected(connectedGraph) == true);

    // Test a disconnected graph
    ariel::Graph disconnectedGraph;
    vector<vector<int>> disconnectedGraphData = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}};
    disconnectedGraph.loadGraph(disconnectedGraphData);
    CHECK(ariel::Algorithms::isConnected(disconnectedGraph) == false);

    // Test an empty graph
    ariel::Graph emptyGraph;
    CHECK(ariel::Algorithms::isConnected(emptyGraph) == true);

    // Test a graph with a single node
    ariel::Graph singleNodeGraph;
    singleNodeGraph.loadGraph({{0}});
    CHECK(ariel::Algorithms::isConnected(singleNodeGraph) == true);

    // Test a graph with multiple connected components
    ariel::Graph multipleComponentsGraph;
    vector<vector<int>> multipleComponentsGraphData = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    multipleComponentsGraph.loadGraph(multipleComponentsGraphData);
    CHECK(ariel::Algorithms::isConnected(multipleComponentsGraph) == false);

    std::vector<std::vector<int>> graph7 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 0}
    };
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    std::vector<std::vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    g.loadGraph(graph3);

    // Test case 1: Source and destination are the same vertex
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");

    // Test case 2: Shortest path exists
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 2 -> 4");

    // Test case 3: No path exists
    CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "-1");

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 20},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4); // Load the graph to the object.
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 2 -> 3 -> 4");

    vector<vector<int>> graph5 = {
    {0, 2},
    {0, 0}
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0 -> 1");

    // A graph where the source and destination vertices are not connected. 
    vector<vector<int>> graph6 = {
    {0, 0},
    {0, 0}
    };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "-1");

    //Weighted Paths   
    vector<vector<int>> graph7 = {
    {0, 2, 0, 4},
    {0, 0, 3, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 0}
    };
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0 -> 3");
    //Negative Weight
    vector<vector<int>> graph8 = {
    {0, 2, 0, -1},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
    };
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0 -> 3");

     // Negative weighted undirected graph
    std::vector<std::vector<int>> graph9 = {
        {0, 2, -5, -1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph9);

    // Test shortest path
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 2");

      // Negative weighted undirected graph
    std::vector<std::vector<int>> graph10 = {
        {0, 2, 4, -1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph10);

    // Test shortest path
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");



}
TEST_CASE("Test shortestPath for non-negative weighted undirected graph")
{
    ariel::Graph g;
    // Non-negative weighted undirected graph
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // Test shortest path
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0 -> 1 -> 2");
}

TEST_CASE("Test shortestPath for weighted directed graph")
{
    ariel::Graph g;
    // Weighted directed graph
    std::vector<std::vector<int>> graph = {
        {0, 1, 2, 0, 20},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph);
    // Test shortest path
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0 -> 2 -> 3 -> 4");   
}

TEST_CASE("Test isContainsCycle")
{
    // Test an empty graph 
    ariel::Graph g;
    vector<vector<int>> graph ;
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test a graph with a single node
    ariel::Graph singleNodeGraph;
    singleNodeGraph.loadGraph({{0}});
    CHECK(ariel::Algorithms::isContainsCycle(singleNodeGraph) == false);


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test a graph without cycles
    vector<vector<int>> acyclicGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(acyclicGraph);

    CHECK(ariel::Algorithms::isContainsCycle(g) == false); // No cycle should be found

    // Test a graph with a cycle
    vector<vector<int>> cyclicGraph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g.loadGraph(cyclicGraph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true); 

    // Test a graph with a cycle
    vector<vector<int>> cyclicGraph1 = {
        {0, 1, 0 ,0 ,0},
        {0, 0, 1 ,0 ,0},
        {0, 0, 0 ,1 ,0},
        {1, 0, 0 ,0 ,1},
        {0, 0, 1 ,0 ,0}
    };
    g.loadGraph(cyclicGraph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true); 

    vector<vector<int>> cyclic = {
        {0, 0 ,1},
        {1, 0 ,0},
        {0, 0 ,0}
    };
    g.loadGraph(cyclic);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false); 

    vector<vector<int>> cyclicGraph3 = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(cyclicGraph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false); 

    vector<vector<int>> graph22 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph22); // Load the graph to the object.
    CHECK(ariel::Algorithms::isContainsCycle(g) == true); 
    vector<vector<int>> graph33 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph33); // Load the graph to the object.
    CHECK(ariel::Algorithms::isContainsCycle(g) == true); 

}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test hasPath") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::hasPath(g, 0, 2) == true);
    CHECK(ariel::Algorithms::hasPath(g, 1, 2) == true);
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::hasPath(g, 0, 4) == false);
    CHECK(ariel::Algorithms::hasPath(g, 1, 3) == true);
    CHECK(ariel::Algorithms::hasPath(g, 1, 4) == false);
    CHECK(ariel::Algorithms::hasPath(g, 0, 3) == true);
    CHECK(ariel::Algorithms::hasPath(g, 4, 3) == false);

    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::hasPath(g, 3, 1) == true);
    CHECK(ariel::Algorithms::hasPath(g, 0, 3) == true);
    CHECK(ariel::Algorithms::hasPath(g, 3, 0) == true);
    CHECK(ariel::Algorithms::hasPath(g, 3, 2) == true);
}
TEST_CASE("Testing negativeCycle function") {
    // Create a graph with a negative cycle
    ariel::Graph g_negative_cycle;
    std::vector<std::vector<int>> graph_with_negative_cycle = {
        {0, -1, 0, 0},
        {0, 0, -1, 0},
        {-1, 0, 0, -1},
        {0, 0, 0, 0}
    };
    g_negative_cycle.loadGraph(graph_with_negative_cycle);

    // Check if the negativeCycle function detects the negative cycle
    CHECK(ariel::Algorithms::negativeCycle(g_negative_cycle) == true);

    // Create a graph without a negative cycle
    ariel::Graph g_no_negative_cycle;
    std::vector<std::vector<int>> graph_without_negative_cycle = {
        {0, 2, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 3},
        {0, 0, 0, 0}
    };
    g_no_negative_cycle.loadGraph(graph_without_negative_cycle);

    // Check if the negativeCycle function correctly reports no negative cycle
    CHECK(ariel::Algorithms::negativeCycle(g_no_negative_cycle) == false);

    // Create a graph without a negative cycle
    ariel::Graph negative_cycle;
    std::vector<std::vector<int>> graph_with_a__negative_cycle = {
        {0, 2, 0, 0},
        {0, 0, -5, 0},
        {1, 0, 0, -1},
        {0, 0, 0, 0}
    };
    negative_cycle.loadGraph(graph_with_a__negative_cycle);
    CHECK(ariel::Algorithms::negativeCycle(negative_cycle) == true);

    std::vector<std::vector<int>> graph_with_out__negative_cycle = {
        {0, 2, 0, 0},
        {0, 0, -1, 0},
        {1, 0, 0, -1},
        {0, 0, 0, 0}
    };
    negative_cycle.loadGraph(graph_with_out__negative_cycle);
    CHECK(ariel::Algorithms::negativeCycle(negative_cycle) == false);
}