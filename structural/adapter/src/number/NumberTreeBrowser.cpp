#include "NumberTreeBrowser.hpp"

#include "GraphicNode.hpp"
#include "Node.hpp"
#include "NumberEntity.hpp"

NumberTreeBrowser::NumberTreeBrowser(std::unique_ptr<NumberEntity> ne) : e{std::move(ne)} {}

std::list<std::unique_ptr<Node>> NumberTreeBrowser::getChildren(const TreeDisplay* display, Node* n) const {
    std::list<std::unique_ptr<Node>> nodes{};
    auto ne = (n == nullptr) ? e.get() : correspondence_map.at(n);
    for (auto& child : ne->children) {
        auto node                      = std::make_unique<Node>(n, std::to_string(child.number));
        correspondence_map[node.get()] = &child;
        nodes.push_back(std::move(node));
    }
    return nodes;
}

std::unique_ptr<GraphicNode> NumberTreeBrowser::createGraphicNode(const TreeDisplay* display, Node* n) const {
    return std::make_unique<GraphicNode>(n->text, n->depth());
}
