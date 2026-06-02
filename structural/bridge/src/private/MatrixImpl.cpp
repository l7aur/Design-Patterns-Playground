#include "MatrixImpl.hpp"

#include <sstream>

MatrixImpl::MatrixImpl(const int n)
    : available_reservations{ n }
{
    adj.resize(available_reservations);
}

int MatrixImpl::getNumberOfNodes() const
{
    return adj.size() - available_reservations;
}

void MatrixImpl::addNode(const int n)
{
    if (available_reservations <= 0)
        throw std::runtime_error("The node id exceeds the reserved size of the adjacency matrix!");

    adj.at(n) = std::vector<int>(adj.size(), MatrixImpl::NOTHING);
    available_reservations--;
}

void MatrixImpl::addUnidirectionalEdge(const int n1, const int n2, const int w)
{
    if (w <= NOTHING)
        throw std::runtime_error("Cannot declare non positive values as weights!");

    adj.at(n1).at(n2) = w;
}

std::string MatrixImpl::print() const
{
    std::stringstream ss;

    for (int i = 0; i < adj.size(); i++) {
        if (adj.at(i).empty())
            continue;

        ss << "Neighbors of node '" << i << "': ";
        for (int j = 0; j < adj.at(i).size(); j++)
            if (adj.at(i).at(j) != NOTHING)
                ss << j << " (" << adj.at(i).at(j) << ") ";
        ss << "\n";
    }
    ss << "\n";

    return ss.str();
}

std::list<std::pair<int, int>> MatrixImpl::neighbors(const int n) const
{
    std::list<std::pair<int, int>> ns{};

    for (int i = 0; i < adj.at(n).size(); i++)
        if (adj.at(n).at(i) != NOTHING)
            ns.emplace_back(std::make_pair(i, adj.at(n).at(i)));

    return ns;
}
