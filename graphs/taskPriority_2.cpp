#include <iostream>
#include <map>
#include <utility>
#include <vector>

struct Edge
{
    char src, dest;
};

class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    //std::vector<std::vector<int>> adjList;

    std::map<char, std::vector<char>> adjList;
    
    // Graph Constructor
    Graph(std::vector<Edge> const &edges)
    {
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

void printGraph(Graph const &graph)
{
    std::cout << "Printing out the graph \n";
    for(const auto& value : graph.adjList)
    {
        std::cout << "Source node: " << value.first << " \nconnected elements: " << std::endl;
        
        for(const auto& element: value.second)
        {
            std::cout << element << " ";
        }

        std::cout <<"\n" << std::endl;
    }

}
bool linearization(Graph graph, int numberOfNodes)
{
    std::vector<int> inDegreeArr (numberOfNodes);

    return true;

}

int main()
{

    std::vector<Edge> edges =
    {
    {'a', 'b'}, {'b', 'c'}, {'c', 'a'}
    };

    //construct graph
    Graph graph(edges);
    printGraph(graph);
}