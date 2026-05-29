#pragma once

#include "SolvingStrategy.hpp"

#include <memory>

class DeterminantComputationStrategy;

class CramersRule : public SolvingStrategy
{
public:
    CramersRule(
        std::unique_ptr<DeterminantComputationStrategy> strategy_
    );
    ~CramersRule() = default;

    virtual std::vector<double> apply(
        const std::vector<std::vector<double>>& x,
        const std::vector<double>& y
    ) const override;

private:
    std::unique_ptr<DeterminantComputationStrategy> strategy;
};