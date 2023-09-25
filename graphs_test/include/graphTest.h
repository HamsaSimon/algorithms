#include <gtest/gtest.h>
#define private public
#include "graph.h"

// Test fixture for typed tests
template <typename T>
class GraphTest : public ::testing::Test 
{
public:
    Graph<T> graph;
};




// Tests that the default constructor creates an empty graph
TYPED_TEST_SUITE_P(GraphTest);
TYPED_TEST_P(GraphTest, DefaultConstructor)
{
    EXPECT_TRUE(this->graph.adjList_.empty());
}

// Tests that the graph is constructed correctly from a vector of edges
TYPED_TEST_P(GraphTest, GraphConstructor)
{
    std::vector<typename Graph<TypeParam>::Edge> edges = {{'A', 'B'}, {'B', 'C'}, {'C', 'A'}};
    
    char startingNode = 'A';
    Graph<TypeParam> graph(edges, startingNode);
    EXPECT_EQ(graph.adjList_['A'], std::vector<TypeParam>({'B'}));
    EXPECT_EQ(graph.adjList_['B'], std::vector<TypeParam>({'C'}));
    EXPECT_EQ(graph.adjList_['C'], std::vector<TypeParam>({'A'}));
}

TYPED_TEST_P(GraphTest, DFSTest)
{
    // Here I'm trying to create a graph with directed edges.
    // Note, how the src node will have a destination only if there's a
    // directed edge towards that node.
    std::vector<Graph<char>::Edge> edges = 
    {
        {'e', 'a'}, {'e', 'i'}, {'a','c'}, {'a', 'h'}, {'c', 'd'} , {'h', 'g'},
        {'d', 'f'}, {'f', 'j'}, {'j', 'c'}, {'g', 'i'},{'i', 'h'}, {'b','a'}, {'b','g'}
    };

    char startingNode = 'b';
    Graph<char> graph(edges, startingNode);
    graph.DFS();

    // The expected values I got from homework # 3 exercise from my algorithm's class
    EXPECT_EQ(graph.visitCountMap_['b'].preVisitNum,1);
    EXPECT_EQ(graph.visitCountMap_['b'].postVisitNum,18);
    EXPECT_EQ(graph.visitCountMap_['a'].preVisitNum, 2);
    EXPECT_EQ(graph.visitCountMap_['a'].postVisitNum, 17);
    EXPECT_EQ(graph.visitCountMap_['c'].preVisitNum, 3);
    EXPECT_EQ(graph.visitCountMap_['c'].postVisitNum, 10);
    EXPECT_EQ(graph.visitCountMap_['d'].preVisitNum, 4);
    EXPECT_EQ(graph.visitCountMap_['d'].postVisitNum, 9);
    EXPECT_EQ(graph.visitCountMap_['f'].preVisitNum, 5);
    EXPECT_EQ(graph.visitCountMap_['f'].postVisitNum, 8);
    EXPECT_EQ(graph.visitCountMap_['j'].preVisitNum, 6);
    EXPECT_EQ(graph.visitCountMap_['j'].postVisitNum, 7);
    EXPECT_EQ(graph.visitCountMap_['h'].preVisitNum, 11);
    EXPECT_EQ(graph.visitCountMap_['h'].postVisitNum, 16);
    EXPECT_EQ(graph.visitCountMap_['g'].preVisitNum, 12);
    EXPECT_EQ(graph.visitCountMap_['g'].postVisitNum, 15);
    EXPECT_EQ(graph.visitCountMap_['i'].preVisitNum, 13);
    EXPECT_EQ(graph.visitCountMap_['i'].postVisitNum, 14);
    EXPECT_EQ(graph.visitCountMap_['e'].preVisitNum, 19);
    EXPECT_EQ(graph.visitCountMap_['e'].postVisitNum, 20);
}

// Register the tests
REGISTER_TYPED_TEST_SUITE_P(GraphTest, DefaultConstructor, GraphConstructor, DFSTest);

// Runs the tests for int and char types
typedef ::testing::Types<int,char, double> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(My, GraphTest, MyTypes);