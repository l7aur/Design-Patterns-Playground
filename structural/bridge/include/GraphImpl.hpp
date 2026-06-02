#pragma once

#include <string>
#include <list>

class GraphImpl
{
public:
    virtual ~GraphImpl() = default;

    virtual int getNumberOfNodes() const = 0;
    virtual void addNode(const int n) = 0;
    virtual void addUnidirectionalEdge(const int n1, const int n2, const int w) = 0;
    virtual std::string print() const = 0;
    virtual std::list<std::pair<int, int>> neighbors(const int n) const = 0;

protected:
    GraphImpl() = default;
};