#include "LinearSystem.hpp"
#include "CramersRule.hpp"
#include "GaussianElimination.hpp"
#include "GaussJordanElimination.hpp"
#include "SarrusRule.hpp"

#include <iostream>

void printSolution(
    const std::vector<double>& sol
);

int main(int argc, char* argv[])
{
    auto ls = LinearSystem(std::make_unique<CramersRule>(std::make_unique<SarrusRule>()));

    // Test 1
    ls.setNumberOfEquations(3);
    ls.setNumberOfVariables(3);
    ls.setEquation(0, { 1.0, 1.0, 1.0 }, -7.0);
    ls.setEquation(1, { 2.0, 0.0, -2.0 }, 10.4);
    ls.setEquation(2, { 5.0, -3.0, 0.0 }, -22.1);

    ls.print(std::cout);

    auto solution = ls.solve();
    printSolution(solution);

    // Test 2
    ls.setNumberOfEquations(2);
    ls.setNumberOfVariables(2);
    ls.setEquation(0, { 1.0, 1.0 }, 10.0);
    ls.setEquation(1, { 2.0, 5.0 }, 41.0);

    ls.print(std::cout);

    solution = ls.solve();
    printSolution(solution);

    // Test 3
    ls.setNumberOfEquations(1);
    ls.setNumberOfVariables(1);
    ls.setEquation(0, { 21.0, }, 115.5);

    ls.print(std::cout);

    solution = ls.solve();
    printSolution(solution);

    return 0;
}

void printSolution(
    const std::vector<double>& sol
)
{
    std::cout << "Solution of the system is: { ";
    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol.at(i);

        if (i != sol.size() - 1)
            std::cout << ";";
        std::cout << " ";
    }
    std::cout << "}\n";
}