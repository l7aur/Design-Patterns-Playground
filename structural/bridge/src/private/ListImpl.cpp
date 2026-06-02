#include "ListImpl.hpp"

#include <sstream>

int ListImpl::getNumberOfNodes() const
{
    return adj.size();
}

void ListImpl::addNode(const int n)
{
    adj.insert_or_assign(n, std::set<std::pair<int, int>>());
}

void ListImpl::addUnidirectionalEdge(const int n1, const int n2, const int w)
{
    adj.at(n1).insert(std::make_pair(n2, w));
}

std::string ListImpl::print() const
{
    std::stringstream ss;

    for (const auto& n : adj) {
        ss << "Neighbors of node '" << n.first << "': ";
        for (const auto& [neighb, w] : n.second)
            ss << neighb << " (" << w << ") ";
        ss << "\n";
    }
    ss << "\n";

    return ss.str();
}

std::list<std::pair<int, int>> ListImpl::neighbors(const int n) const
{
    std::list<std::pair<int, int>> ns{};

    for (const auto& nw : adj.at(n))
        ns.emplace_back(nw);

    return ns;
}
