#include "../graph.h"

int main()
{
    // undirected edges
    std::vector<Graph::Edge> edges = 
    {
        {'g', 'd'}, {'g','h'} , {'d', 'h'},
        {'d', 'g'}, {'h', 'g'}, {'h', 'd'},
        {'d', 'a'}, {'a', 'd'}, {'a', 'b'},
        {'b', 'a'}, {'a', 'c'}, {'c', 'a'},
        {'c', 'f'}, {'f', 'c'},
        {'b', 'f'}, {'f', 'b'}, {'b', 'e'},
        {'e', 'b'}, {'e', 'i'}, {'i', 'e'},
        {'e', 'j'}, {'j', 'e'},
        {'i', 'j'}, {'j', 'i'}, {'k', 'l'},
        {'l', 'k'}
    };

    Graph graph(edges);
    //printGraph(graph);

    graph.DFS();
}