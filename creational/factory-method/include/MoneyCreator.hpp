#pragma once

#include <memory>

class Money;

template <typename T>
class MoneyCreator
{
    static_assert(std::is_base_of_v<Money, T>);

public:
    static std::unique_ptr<Money> create(int value)
    {
        return std::make_unique<T>(value);
    }
};