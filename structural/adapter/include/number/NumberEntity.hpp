#pragma once

#include <list>

struct NumberEntity {
    NumberEntity(int x);

    static NumberEntity create();

    std::list<NumberEntity> children;
    int number;
};