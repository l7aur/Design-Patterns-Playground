#pragma once

#include <map>

#include "TreeAccessorDelegate.hpp"

struct NumberEntity;

class NumberTreeBrowser : public TreeAccessorDelegate {
public:
    NumberTreeBrowser(std::unique_ptr<NumberEntity> ne);
    std::list<std::unique_ptr<Node>> getChildren(const TreeDisplay* display, Node* n) const override;
    std::unique_ptr<GraphicNode> createGraphicNode(const TreeDisplay* display, Node* n) const override;

private:
    mutable std::map<Node*, NumberEntity*> correspondence_map;
    std::unique_ptr<NumberEntity> e;
};
