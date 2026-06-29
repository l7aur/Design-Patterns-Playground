#pragma once

#include "Money.hpp"

class Euro : public Money
{
public:
    Euro(const int x) : Money{x} {}
    int convertToRobux() const override;
};