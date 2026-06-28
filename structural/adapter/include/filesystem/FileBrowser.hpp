#pragma once

#include <map>

#include "TreeAccessorDelegate.hpp"

struct FileSystemEntity;

class FileBrowser : public TreeAccessorDelegate {
public:
    FileBrowser(std::unique_ptr<FileSystemEntity> fse);
    std::list<std::unique_ptr<Node>> getChildren(const TreeDisplay* display, Node* n) const override;
    std::unique_ptr<GraphicNode> createGraphicNode(const TreeDisplay* display, Node* n) const override;

private:
    mutable std::map<Node*, FileSystemEntity*> correspondence_map;
    std::unique_ptr<FileSystemEntity> e;
};
