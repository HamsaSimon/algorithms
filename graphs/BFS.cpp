#include <iostream>
#include <vector>
#include <list>

// This class represents a directed graph using
// adjaceny list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists
    std::vector<std::list<int>> adj;

    // Pointer to an array containing a count list
    std::vector<std::list<int>> countList;

    std::vector<int> countVec;

    public:

        Graph(int V); // Constructor

        // function to add an edge to graph
        void addEdge(int v, int  w);

        // print BFS traversal from a given source s
        void BFS(int s);

        void initCountList(int V);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::initCountList(int V)
{
    for(uint i = 0; i < V; i++)
    {
        countVec[i] = 0;
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.

}

void Graph::BFS(int s)
{
    // Mark all vertices as not visited
    std::vector<bool> visited;
    visited.resize(V,false);

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    countVec[s] = 1; // start node (one path from s to s)

    while(!(queue.empty()))
    {
        
        s = queue.front();
        // Dequeue a vertex from queue and print it
        queue.pop_front();
        std::cout << "starting node is " << s << "\n";

        // Get all adjacent vertices of the dequeued
        // vertex s. If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent: adj[s])
        {
            std::cout << "adjacent node that we are looking at " << adjacent << std::endl;
            countVec[adjacent] +=1;
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
    
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);

    return 0;
}