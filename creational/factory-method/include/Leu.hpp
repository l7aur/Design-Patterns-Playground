#pragma once

#include "Money.hpp"

class Leu : public Money
{
public:
    Leu(const int x) : Money{x} {}
    int convertToRobux() const override;
};