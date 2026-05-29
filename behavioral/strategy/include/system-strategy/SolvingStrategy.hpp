#pragma once

#include <vector>
#include <stdexcept>

class SolvingStrategy {
public:
    virtual std::vector<double> apply(
        const std::vector<std::vector<double>>& x,
        const std::vector<double>& y
    ) const = 0;
};