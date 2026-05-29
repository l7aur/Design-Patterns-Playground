#pragma once

#include <vector>
#include <cassert>
#include <stdexcept>

class DeterminantComputationStrategy
{
public:
    virtual double determinant(
        const std::vector<std::vector<double>>& matrix
    ) const = 0;
};