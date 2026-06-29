#pragma once

#include <memory>

class Money;

class MoneyCreator
{
public:
    static std::unique_ptr<Money> createDollars(int value);
    static std::unique_ptr<Money> createEuros(int value);
    static std::unique_ptr<Money> createLions(int value);
};