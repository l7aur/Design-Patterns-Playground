#pragma once

#include <vector>
#include <memory>
#include <iostream>

class SolvingStrategy;

class LinearSystem {
public:
    LinearSystem(
        std::unique_ptr<SolvingStrategy> strategy_
    );
    ~LinearSystem() = default;

    void setNumberOfVariables(
        const unsigned int numberOfVariables
    );
    void setNumberOfEquations(
        const unsigned int numberOfEquations
    );
    void setEquation(
        const unsigned int equationIndex,
        const std::initializer_list<double>& coefficients,
        const double result
    );
    std::vector<double> solve() const;
    void print(
        std::ostream& out
    ) const;

private:
    unsigned int numberOfEquations{ 0 };
    unsigned int numberOfVariables{ 0 };
    std::vector<std::vector<double>> x{};
    std::vector<double> y{};
    std::unique_ptr<SolvingStrategy> strategy;
};