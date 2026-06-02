#pragma once

#include "GraphImpl.hpp"

#include <map>
#include <set>

class ListImpl : public GraphImpl
{
public:
    ListImpl() = default;
    ~ListImpl() override = default;

    int getNumberOfNodes() const override;
    void addNode(const int n) override;
    void addUnidirectionalEdge(const int n1, const int n2, const int w) override;
    std::string print() const override;
    std::list<std::pair<int, int>> neighbors(const int n) const override;

private:
    std::map<int, std::set<std::pair<int, int>>> adj{};
};