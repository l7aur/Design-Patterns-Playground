#pragma once

#include "Graph.hpp"

class DirectedGraph : public Graph
{
public:
    DirectedGraph(std::unique_ptr<GraphImpl> impl_);
    ~DirectedGraph() override = default;
};