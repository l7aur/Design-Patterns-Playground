#pragma once

#include <vector>

class DeterminantComputationStrategy
{
public:
    virtual double determinant(
        const std::vector<std::vector<double>>& matrix
    ) const = 0;
};