#pragma once

#include "SolvingStrategy.hpp"

class GaussianElimination : public SolvingStrategy
{
public:
    virtual std::vector<double> apply(
        const std::vector<std::vector<double>>& x,
        const std::vector<double>& y
    ) const override;
};