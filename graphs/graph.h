#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>


template<class T>
class Graph
{
public:

    struct Edge
    {
        T src, dest;
        int preVisitNum, postVisitNum;
    };

    std::unordered_map<T, std::vector<T>> adjList_;

    // marks which nodes have been visited. True = visited, false = not visited
    std::map<T, bool> visited_;
    
    //Default constructor
    Graph() {}
    
    // Graph Constructor
    Graph(std::vector<Edge> const &edges);

    void DFS();

    void explore(T vertex);

    void previst(T vertex);
    
    void postvist(T vertex);

private:

    static int currVisitNum;
};

template<class T>
int Graph<T>::currVisitNum = 0;

template<class T>
Graph<T>::Graph(std::vector<Edge> const &edges)
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

template<class T>
void Graph<T>::DFS()
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


template<class T>
void Graph<T>::explore(T vertex)
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

template<class T>
void Graph<T>::previst(T vertex)
{
    std::cout << "Pre visiting vertex: " << vertex << std::endl;
}

template<class T>
void Graph<T>::postvist(T vertex)
{
    std::cout << "Post visting vertex: " << vertex << std::endl;
}

inline void printGraph(Graph<char> const &graph)
{
    std::cout << "Printing out the graph \n";
    for(const auto& value : graph.adjList_)
    {
        std::cout << "Source node: " << value.first << " \nconnected elements: " << std::endl;
        
        for(const auto& element: value.second)
        {
            std::cout << element << " ";
        }

        std::cout <<"\n" << std::endl;
    }

}

#endif //GRAPH_H 