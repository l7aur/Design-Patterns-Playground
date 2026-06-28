#pragma once

#include <ostream>
#include <string>

class GraphicNode {
public:
    GraphicNode(const std::string& display, int indentation = 0) : display_text{display}, indent{indentation} {}

    friend std::ostream& operator<<(std::ostream& out, const GraphicNode& n) {
        out << std::string(n.indent, '>') << n.display_text << "\n";
        return out;
    }

private:
    std::string display_text;
    int indent;
};
