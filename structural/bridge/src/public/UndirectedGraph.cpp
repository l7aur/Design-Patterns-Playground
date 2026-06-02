#include "UndirectedGraph.hpp"

#include "GraphImpl.hpp"

UndirectedGraph::UndirectedGraph(std::unique_ptr<GraphImpl> impl_)
    : Graph{ std::move(impl_) }
{ }

void UndirectedGraph::addEdge(const int n1, const int n2, const int w)
{
    getImplementation()->addUnidirectionalEdge(n1, n2, w);
    getImplementation()->addUnidirectionalEdge(n2, n1, w);
}