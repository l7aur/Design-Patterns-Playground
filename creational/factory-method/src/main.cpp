#include <iostream>
#include "MoneyCreator.hpp"
#include "Money.hpp"

int main(int argc, char *argv[])
{
    // auto something = MoneyCreator::createEuros(10);
    auto something = MoneyCreator::createLions(10);

    std::cout << something->convertToRobux();

    return 0;
}