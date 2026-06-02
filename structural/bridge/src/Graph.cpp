#include "Graph.hpp"

#include "GraphImpl.hpp"

void Graph::addNode(const int n)
{
    impl->addNode(n);
}

void Graph::addEdge(const int n1, const int n2, const int w)
{
    impl->addUnidirectionalEdge(n1, n2, w);
}

std::string Graph::print() const
{
    return impl->print();
}

Graph::Graph(std::unique_ptr<GraphImpl> impl_)
    : impl{ std::move(impl_) }
{ }

GraphImpl *Graph::getImplementation() const
{
    return impl.get();
}
