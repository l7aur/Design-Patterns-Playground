#pragma once

#include <list>
#include <memory>

struct Node;
class GraphicNode;
class TreeDisplay;

class TreeAccessorDelegate {
public:
    /**
     * Provide reference to `TreeDisplay` object to access style resources like
     *  font family, background/foreground color etc.
     */
    virtual std::list<std::unique_ptr<Node>> getChildren(const TreeDisplay* display, Node* n) const   = 0;
    virtual std::unique_ptr<GraphicNode> createGraphicNode(const TreeDisplay* display, Node* n) const = 0;
};
