#include "CramersRule.hpp"
#include "DeterminantComputationStrategy.hpp"

namespace
{
    std::vector<std::vector<double>> exchangeColumn(
        const std::vector<std::vector<double>>& matrix,
        const unsigned int columnIndex,
        const std::vector<double>& newColumn
    )
    {
        if (matrix.empty())
            return matrix;

        if (newColumn.size() != matrix.size())
            throw std::invalid_argument("New column size must match matrix row count");

        auto r = matrix;
        for (unsigned int i = 0; i < r.size(); i++)
            r.at(i).at(columnIndex) = newColumn.at(i);

        return r;
    }
}

CramersRule::CramersRule(
    std::unique_ptr<DeterminantComputationStrategy> strategy_
) : strategy { std::move(strategy_) }
{ }

std::vector<double> CramersRule::apply(
    const std::vector<std::vector<double>> &x,
    const std::vector<double> &y) const
{
    if (x.size() > 3 || x.front().size() > 3)
        throw std::runtime_error("We do not support matrices greater than 3x3");

    auto det_x = strategy->determinant(x);
    if (det_x == 0)
        throw std::runtime_error("The matrix of the system is singular");

    auto result = std::vector<double>(y.size());
    for (int i = 0; i < result.size(); i++)
        result.at(i) = strategy->determinant(exchangeColumn(x, i, y)) / det_x;

    return result;
}