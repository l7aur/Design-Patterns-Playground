#include "MoneyCreator.hpp"

#include "Money.hpp"
#include "Leu.hpp"
#include "Dollar.hpp"
#include "Euro.hpp"

std::unique_ptr<Money> MoneyCreator::createDollars(const int value)
{
    return std::make_unique<Dollar>(value);
}

std::unique_ptr<Money> MoneyCreator::createEuros(const int value)
{
    return std::make_unique<Euro>(value);
}

std::unique_ptr<Money> MoneyCreator::createLions(const int value)
{
    return std::make_unique<Leu>(value);
}
