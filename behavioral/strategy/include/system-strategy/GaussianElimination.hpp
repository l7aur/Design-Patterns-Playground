#pragma once

#include "SolvingStrategy.hpp"

class GaussianElimination : public SolvingStrategy
{
public:
    virtual std::vector<double> apply(
        const std::vector<std::vector<double>>& x,
        const std::vector<double>& y
    ) const override;

private:
    int findIndexOfFirstRowWithNonNullEntryAt(
        const std::vector<std::vector<double>>& matrix,
        const unsigned int columnIndex
    ) const;
    void swapRows(
        std::vector<std::vector<double>>& matrix,
        std::vector<double>& y,
        const unsigned int r1,
        const unsigned int r2
    ) const;
    void linearTransformRow(
        std::vector<double>& x_row,
        const std::vector<double>& x_row_pivot,
        double& y_value,
        const double& y_pivot
    ) const;
    void backSubstitution(
        std::vector<std::vector<double>>& matrix,
        std::vector<double>& y,
        const unsigned int rowIndex,
        const double variableValue
    ) const;
};