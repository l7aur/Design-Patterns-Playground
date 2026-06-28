#include <iostream>

#include "DirectoryBrowser.hpp"
#include "FileBrowser.hpp"
#include "FileSystemEntity.hpp"
#include "Node.hpp"
#include "TreeDisplay.hpp"

int main(int argc, char* argv[]) {
    TreeDisplay td{};
    td.setDelegate(std::make_unique<FileBrowser>(std::make_unique<FileSystemEntity>("..")));
    td.buildTree(nullptr);
    td.display(std::cout);

    return 0;
}
