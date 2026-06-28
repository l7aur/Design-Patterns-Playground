#pragma once

#include <memory>
#include <sstream>

struct Node;
class GraphicNode;
class TreeAccessorDelegate;

class TreeDisplay {
public:
    void display(std::ostream& out) const;
    void buildTree(Node* n);
    void setDelegate(std::unique_ptr<TreeAccessorDelegate> d);

private:
    std::unique_ptr<TreeAccessorDelegate> delegate;
    std::stringstream internal_repr{};

    void addGraphicNode(std::unique_ptr<GraphicNode> n);
};
