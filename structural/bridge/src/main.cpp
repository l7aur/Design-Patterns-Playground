#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"
#include "MatrixImpl.hpp"
#include "ListImpl.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    // std::unique_ptr<Graph> g = std::make_unique<UndirectedGraph>(std::make_unique<MatrixImpl>(10));
    // std::unique_ptr<Graph> g = std::make_unique<DirectedGraph>(std::make_unique<ListImpl>());
    std::unique_ptr<Graph> g = std::make_unique<UndirectedGraph>(std::make_unique<ListImpl>());
    // std::unique_ptr<Graph> g = std::make_unique<DirectedGraph>(std::make_unique<MatrixImpl>(100));

    g->addNode(0);
    g->addNode(1);
    g->addNode(2);
    g->addNode(3);
    g->addNode(4);

    g->addEdge(0, 1, 3);
    g->addEdge(0, 2, 7);
    g->addEdge(0, 3, 8);
    g->addEdge(0, 4, 2);
    g->addEdge(3, 4, 1);
    g->addEdge(3, 2, 6);
    g->addEdge(1, 2, 1);

    std::cout << g->print();

    return 0;
}