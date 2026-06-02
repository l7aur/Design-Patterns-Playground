#pragma once

#include "Graph.hpp"

class UndirectedGraph : public Graph
{
public:
    UndirectedGraph(std::unique_ptr<GraphImpl> impl_);
    ~UndirectedGraph() override = default;

    void addEdge(const int n1, const int n2, const int w) override;
};