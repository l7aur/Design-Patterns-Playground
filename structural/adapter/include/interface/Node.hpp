#pragma once

#include <list>
#include <memory>
#include <string>

struct Node {
    Node* parent;
    std::string text{""};
    std::list<std::unique_ptr<Node>> children{};
    int depth() {
        if (parent == nullptr) {
            return 0;
        }
        return 1 + parent->depth();
    }
};
