#include "graph.h"

Graph::Graph(std::vector<Edge> const &edges)
{
    // add edges to the directed graph
    for (auto &edge: edges)
    {
        // insert at the end
        adjList_[edge.src].push_back(edge.dest);
        
        // establish initial visited values for each node
        visited_[edge.src] = false;
    }
}

void Graph::DFS()
{
    // We check for nodes that have not been visited
    for (auto const& x : visited_)
    {
        if (x.second == false)
        {
            explore(x.first);
        }
    }
}

void Graph::explore(char vertex)
{
    visited_[vertex] = true;
    previst(vertex);

    for(auto const& sourceNode : adjList_[vertex])
    {
        if(visited_[sourceNode] == false)
        {
            explore(sourceNode);
        }
    }
    postvist(vertex);
}

void Graph::previst(char vertex)
{
    std::cout << "Pre visiting vertex: " << vertex << std::endl;
}

void Graph::postvist(char vertex)
{
    std::cout << "Post visting vertex: " << vertex << std::endl;
}