#include "NumberEntity.hpp"

NumberEntity::NumberEntity(int x) : number{x} {}

NumberEntity NumberEntity::create() {
    auto root = NumberEntity(1);

    auto c1       = NumberEntity(1);
    auto c2       = NumberEntity(2);
    auto c3       = NumberEntity(3);
    root.children = {c1, c2, c3};

    auto g1                        = NumberEntity(10);
    auto g2                        = NumberEntity(20);
    auto g3                        = NumberEntity(30);
    root.children.front().children = {g1, g2, g3};

    auto g5                       = NumberEntity(50);
    auto g6                       = NumberEntity(60);
    root.children.back().children = {g5, g6};

    auto gg1                                      = NumberEntity(100);
    auto gg2                                      = NumberEntity(200);
    root.children.back().children.back().children = {gg1, gg2};

    return root;
}
