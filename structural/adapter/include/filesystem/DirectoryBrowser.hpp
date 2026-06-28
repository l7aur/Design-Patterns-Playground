#pragma once

#include <filesystem>
#include <map>

#include "TreeAccessorDelegate.hpp"

struct FileSystemEntity;

class DirectoryBrowser : public TreeAccessorDelegate {
public:
    DirectoryBrowser(std::unique_ptr<FileSystemEntity> fse);
    std::list<std::unique_ptr<Node>> getChildren(const TreeDisplay* display, Node* n) const override;
    std::unique_ptr<GraphicNode> createGraphicNode(const TreeDisplay* display, Node* n) const override;

private:
    std::unique_ptr<FileSystemEntity> e;
    mutable std::map<Node*, FileSystemEntity*> conversion_map{};
};
