#include <iostream>

#include "DirectoryBrowser.hpp"
#include "FileBrowser.hpp"
#include "FileSystemEntity.hpp"
#include "Node.hpp"
#include "NumberEntity.hpp"
#include "NumberTreeBrowser.hpp"
#include "TreeDisplay.hpp"

int main(int argc, char* argv[]) {
    TreeDisplay td{};
    // td.setDelegate(std::make_unique<NumberTreeBrowser>(std::make_unique<FileSystemEntity>("..")));
    auto root = NumberEntity::create();
    td.setDelegate(std::make_unique<NumberTreeBrowser>(std::unique_ptr<NumberEntity>(&root)));
    td.buildTree(nullptr);
    td.display(std::cout);

    return 0;
}
