#include <vector>
#include <utility>
#include <iostream>

struct Edge
{
    char src, dest;
};

class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    std::vector<std::vector<int>> adjList_;

    // Graph Constructor
    Graph(std::vector<Edge> const &edges, int n)
    {
        // resize the vector to hold 'n' element of type 'vector<int>'
        adjList_.resize(n);

        // add edges to the directed graph
        for (auto &edge: edges)
        {
            // insert at the end
            adjList_[edge.src].push_back(edge.dest);
        }
    }
};

void printGraph(Graph const &graph, int n)
{

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

    //total number of nodes in the graph
    int nodes = 3;

    //construct graph
    Graph graph(edges, nodes);
}