#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>



class Graph
{
public:

    struct Edge
    {
    char src, dest;
    
    };

    std::unordered_map<char, std::vector<char>> adjList_;

    // marks which nodes have been visited. True = visited, false = not visited
    std::map<char, bool> visited_;

    //std::unordered_set<char> visited_;
    
    // Graph Constructor
    Graph(std::vector<Edge> const &edges);

    void DFS();

    void explore(char vertex);

    void previst(char vertex);
    
    void postvist(char vertex);
};

inline void printGraph(Graph const &graph)
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