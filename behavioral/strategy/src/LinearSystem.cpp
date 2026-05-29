#include "LinearSystem.hpp"
#include "SolvingStrategy.hpp"

#include <assert.h>

LinearSystem::LinearSystem(
    std::unique_ptr<SolvingStrategy> strategy_
)
    : strategy{ std::move(strategy_) }
{ }

void LinearSystem::setNumberOfEquations(
    const unsigned int numberOfEquations
)
{
    this->numberOfEquations = numberOfEquations;
    x.resize(numberOfEquations);
}

void LinearSystem::setEquation(
    const unsigned int equationIndex,
    const std::initializer_list<double> &coefficients,
    const double result
)
{
    assert(equationIndex < numberOfEquations);
    assert(coefficients.size() == numberOfVariables);

    auto& location = x.at(equationIndex);
    for (int i = 0; i < numberOfVariables; i++)
        location.at(i) = *(coefficients.begin() + i);

    y.at(equationIndex) = result;
}

void LinearSystem::setNumberOfVariables(
    const unsigned int numberOfVariables
)
{
    this->numberOfVariables = numberOfVariables;
    for (auto& r : x)
        r.resize(numberOfVariables);
    y.resize(numberOfVariables);
}

std::vector<double> LinearSystem::solve() const
{
    return strategy->apply(x, y);
}

void LinearSystem::print(
    std::ostream &out
) const
{
    for (int i = 0; i < numberOfEquations; i++) {
        const auto& eq = x.at(i);
        for (int j = 0; j < numberOfVariables; j++) {
            const auto& coeff = eq.at(j);
            out << coeff;

            if (coeff != 0)
                out << "*x_" << j;

            out << " ";

            if (j < numberOfVariables - 1)
                out << "+ ";
        }
        out << "= " << y.at(i) << "\n";
    }
}
