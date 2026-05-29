#pragma once

#include "DeterminantComputationStrategy.hpp"

class LeibnizRule : public DeterminantComputationStrategy
{
public:
    double determinant(
        const std::vector<std::vector<double>>& matrix
    ) const override;
};