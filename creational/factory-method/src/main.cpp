#include <iostream>
#include "MoneyCreator.hpp"

#define LEU
// #define EURO
// #define DOLLAR

#ifdef LEU
#include "Leu.hpp"
#elif defined(EURO)
#include "Euro.hpp"
#elif defined(DOLLAR)
#include "Dollar.hpp"
#endif

int main(int argc, char *argv[])
{
#ifdef LEU
    auto something = MoneyCreator<Leu>::create(10);
    std::cout << something->convertToRobux();
#elif defined(EURO)
    auto something = MoneyCreator<Euro>::create(10);
    std::cout << something->convertToRobux();
#elif defined(DOLLAR)
    auto something = MoneyCreator<Dollar>::create(10);
    std::cout << something->convertToRobux();
#endif

    return 0;
}