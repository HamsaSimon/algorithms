#include <gtest/gtest.h>
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
    
    Graph<TypeParam> graph(edges);
    EXPECT_EQ(graph.adjList_['A'], std::vector<TypeParam>({'B'}));
    EXPECT_EQ(graph.adjList_['B'], std::vector<TypeParam>({'C'}));
    EXPECT_EQ(graph.adjList_['C'], std::vector<TypeParam>({'A'}));
}

// Register the tests
REGISTER_TYPED_TEST_SUITE_P(GraphTest, DefaultConstructor, GraphConstructor);

// Runs the tests for int and char types
typedef ::testing::Types<int,char, double> MyTypes;
INSTANTIATE_TYPED_TEST_SUITE_P(My, GraphTest, MyTypes);