#pragma once

#include "GraphImpl.hpp"

#include <vector>

class MatrixImpl : public GraphImpl
{
public:
    MatrixImpl(const int n);
    ~MatrixImpl() override = default;

    int getNumberOfNodes() const override;
    void addNode(const int n) override;
    void addUnidirectionalEdge(const int n1, const int n2, const int w) override;
    std::string print() const override;
    std::list<std::pair<int, int>> neighbors(const int n) const override;

private:
    static constexpr auto NOTHING{ 0 };
    std::vector<std::vector<int>> adj;
    int available_reservations;
};