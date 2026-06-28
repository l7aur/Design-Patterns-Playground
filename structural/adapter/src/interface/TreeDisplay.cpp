#include "TreeDisplay.hpp"

#include <ostream>

#include "GraphicNode.hpp"
#include "Node.hpp"
#include "TreeAccessorDelegate.hpp"

void TreeDisplay::display(std::ostream& out) const {
    out << internal_repr.str() << "\n";
}

void TreeDisplay::buildTree(Node* n) {
    auto children = delegate->getChildren(this, n);

    for (const auto& k : children) {
        auto graphicNode = delegate->createGraphicNode(this, k.get());
        addGraphicNode(std::move(graphicNode));
        buildTree(k.get());
    }
}

void TreeDisplay::addGraphicNode(std::unique_ptr<GraphicNode> n) {
    internal_repr << *n;
}

void TreeDisplay::setDelegate(std::unique_ptr<TreeAccessorDelegate> d) {
    delegate = std::move(d);
}
