#include "SarrusRule.hpp"

double SarrusRule::determinant(
    const std::vector<std::vector<double>>& matrix
) const
{
    if (matrix.empty() || matrix.size() > 3 || matrix.front().size() > 3)
            throw std::invalid_argument("Matrix must be square, smaller than 3x3");

    if (matrix.size() == 3)
        return matrix.at(0).at(0) * matrix.at(1).at(1) * matrix.at(2).at(2) +
            matrix.at(1).at(0) * matrix.at(2).at(1) * matrix.at(0).at(2) +
            matrix.at(0).at(1) * matrix.at(1).at(2) * matrix.at(2).at(0) -
            matrix.at(0).at(2) * matrix.at(1).at(1) * matrix.at(2).at(0) -
            matrix.at(1).at(0) * matrix.at(0).at(1) * matrix.at(2).at(2) -
            matrix.at(0).at(0) * matrix.at(1).at(2) * matrix.at(2).at(1);

    if (matrix.size() == 2)
        return matrix.at(0).at(0) * matrix.at(1).at(1) - matrix.at(0).at(1) * matrix.at(1).at(0);

    return matrix.at(0).at(0);
}