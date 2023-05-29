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

    };

    struct visitCounts
    {
        int preVisitNum, postVisitNum;
    };
    
    // Default constructor
    Graph() {}
    
    // Graph Constructor
    Graph(std::vector<Edge> const &edges, T startingNode);

    void DFS();

    void explore(T vertex);

    void previst(T vertex);
    
    void postvist(T vertex);

    // Prints the PreVisit and Post Visit numbers for each node in the graph
    void printPrePostVisits();

    void printGraph();

private:

    // Static integer to keep track of the number of visits we have done in total    
    static int currVisitNum;

    // Node where we start our DFS search
    T startingNode_;
    
    // marks which nodes have been visited. True = visited, false = not visited
    std::unordered_map<T, bool> visited_;

    // Keeps count the pre/post numbering for each node T
    std::unordered_map<T, visitCounts> visitCountMap_;

    // Adjacency list for graph
    std::unordered_map<T, std::vector<T>> adjList_;
};

    template<class T>
    int Graph<T>::currVisitNum = 0;

template<class T>
Graph<T>::Graph(std::vector<Edge> const &edges, T startingNode)
{
    startingNode_ = startingNode;
    visitCounts visitCountInit = {0,0};
    // add edges to the directed graph
    for (auto &edge: edges)
    {
        // insert at the end
        adjList_[edge.src].push_back(edge.dest);
        
        // establish initial visited values for each node
        visited_[edge.src] = false;

        //establish pre and post visit counts
        visitCountMap_[edge.src] = visitCountInit;
    }
}

template<class T>
void Graph<T>::DFS()
{    
    explore(startingNode_);
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
    visitCountMap_[vertex].preVisitNum = ++currVisitNum;
}

template<class T>
void Graph<T>::postvist(T vertex)
{
    std::cout << "Post visting vertex: " << vertex << std::endl;
    visitCountMap_[vertex].postVisitNum = ++currVisitNum;
}

template<class T>
void Graph<T>::printGraph()
{
    std::cout << "Printing out the graph \n";
    for(const auto& value : adjList_)
    {
        std::cout << "Source node: " << value.first << " \nconnected elements: " << std::endl;
        
        for(const auto& element: value.second)
        {
            std::cout << element << " ";
        }

        std::cout <<"\n" << std::endl;
    }

}

template<class T>
void Graph<T>::printPrePostVisits()
{
    std::cout << "| Node | Pre | Post |\n";
    
    for(const auto& node : visitCountMap_)
    {
        std::cout << "  " <<  node.first << "      " << node.second.preVisitNum << "      " << node.second.postVisitNum << std::endl;
    }

}

#endif //GRAPH_H 