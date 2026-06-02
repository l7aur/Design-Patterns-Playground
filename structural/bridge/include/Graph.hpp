#pragma once

#include <list>
#include <string>
#include <memory>

class GraphImpl;

class Graph
{
public:
    virtual ~Graph() = default;

    virtual void addNode(const int n);
    virtual void addEdge(const int n1, const int n2, const int w);
    virtual std::string print() const;

protected:
    Graph(std::unique_ptr<GraphImpl> impl_);

    GraphImpl* getImplementation() const;

private:
    std::unique_ptr<GraphImpl> impl;
};