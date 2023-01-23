#include <iostream>
#include <vector>
#include <list>

// This class represents a directed graph using
// adjaceny list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing a count list
    std::vector<std::list<int>> countList;

    std::vector<int> countVec;
    
    // Pointer to an array containing adjacency lists
    std::vector<std::list<int>> adj;

    public:

        Graph(int V); // Constructor

        // function to add an edge to graph
        void addEdge(int v, int  w);

        uint getNumberOfNodes();

        uint shortestPaths(int u, int v);

};


Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.

}

uint Graph::getNumberOfNodes()
{
    return adj.size();
}

uint Graph::shortestPaths(int u, int v)
{
    std::list<int> queue;
    queue.push_back(u);

    uint ret = 0;

    // Mark all vertices as not visited
    std::vector<bool> visited;
    visited.resize(this->getNumberOfNodes(),false);

    uint count = 0;

    while (!(queue.empty()) && (ret == 0 || queue.front() == v))
    {
        std::cout << "count is now: " << ++count << std::endl;

        int node = queue.front();
        //dequeue
        queue.pop_front();

        visited[node] = true;

        if(node == v)
        {
            ret++;
        }

        for (auto adjacent: adj[node])
        {
            if (!visited[adjacent])
            {
                queue.push_back(adjacent);
            }
        }
    }
    return ret;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
 
    uint count = g.shortestPaths(0,3);

    std::cout << "The number of distinct shortest paths from 0 to 3 is : " << count << "\n";

    return 0;
}