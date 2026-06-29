#pragma once

#include "Money.hpp"

class Dollar : public Money
{
public:
    Dollar(const int x) : Money{x} {}
    int convertToRobux() const override;
};