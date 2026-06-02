#include "DirectedGraph.hpp"

#include "GraphImpl.hpp"

DirectedGraph::DirectedGraph(std::unique_ptr<GraphImpl> impl_)
    : Graph{ std::move(impl_) }
{ }