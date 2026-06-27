#include "DirectoryBrowser.hpp"

#include "FileSystemEntity.hpp"
#include "GraphicNode.hpp"
#include "Node.hpp"

DirectoryBrowser::DirectoryBrowser(std::unique_ptr<FileSystemEntity> fse) : TreeAccessorDelegate{}, e{std::move(fse)} {}

std::list<std::unique_ptr<Node>> DirectoryBrowser::getChildren(const TreeDisplay* display, Node* n) const {
    FileSystemEntity* fse = (n == nullptr) ? e.get() : conversion_map.at(n);

    std::list<std::unique_ptr<Node>> children;
    for (FileSystemEntity& child : fse->entities) {
        auto node                  = std::make_unique<Node>(n, child.path.filename().string());
        conversion_map[node.get()] = &child;
        children.push_back(std::move(node));
    }

    return children;
}

std::unique_ptr<GraphicNode> DirectoryBrowser::createGraphicNode(const TreeDisplay* display, Node* n) const {
    /* use `display` to query for style */
    return std::make_unique<GraphicNode>(n->text, n->depth());
}

void DirectoryBrowser::convert(Node* n, FileSystemEntity* ent) const {}
