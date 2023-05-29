#include "../graph.h"

int main()
{
    // undirected edges
    // std::vector<Graph<char>::Edge> edges = 
    // {
    //     {'g', 'd'}, {'g','h'} , {'d', 'h'},
    //     {'d', 'g'}, {'h', 'g'}, {'h', 'd'},
    //     {'d', 'a'}, {'a', 'd'}, {'a', 'b'},
    //     {'b', 'a'}, {'a', 'c'}, {'c', 'a'},
    //     {'c', 'f'}, {'f', 'c'},
    //     {'b', 'f'}, {'f', 'b'}, {'b', 'e'},
    //     {'e', 'b'}, {'e', 'i'}, {'i', 'e'},
    //     {'e', 'j'}, {'j', 'e'},
    //     {'i', 'j'}, {'j', 'i'}, {'k', 'l'},
    //     {'l', 'k'}
    // };

    // Here I'm trying to create a graph with directed edges.
    // Note, how the src node will have a destination only if there's a
    // directed edge towards that node.
    // TODO: add a mechanism to restart on second start node
    std::vector<Graph<char>::Edge> edges = 
    {
        {'e', 'a'}, {'e', 'i'}, {'a','c'}, {'a', 'h'}, {'c', 'd'} , {'h', 'g'},
        {'d', 'f'}, {'f', 'j'}, {'j', 'c'}, {'g', 'i'},{'i', 'h'}, {'b','a'}, {'b','g'}
    };

    char startingNode = 'e';
    Graph<char> graph(edges, startingNode);
    //printGraph(graph);
    graph.DFS();
    graph.printPrePostVisits();
}