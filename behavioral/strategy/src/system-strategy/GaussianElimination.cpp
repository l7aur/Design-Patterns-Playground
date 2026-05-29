#include "GaussianElimination.hpp"

std::vector<double> GaussianElimination::apply(
    const std::vector<std::vector<double>>& x,
    const std::vector<double>& y
) const
{
    auto current_x = x;
    auto current_y = y;

    for (unsigned int i = 0; i < current_x.size() - 1; i++) {
        auto& pivot_line = current_x.at(i);

        if (pivot_line.at(i) == 0) {
            auto index = findIndexOfFirstRowWithNonNullEntryAt(current_x, i);
            swapRows(current_x, current_y, i, index);
        }

        for (unsigned int j = i + 1; j < current_x.size(); j++)
            linearTransformRow(current_x.at(j), current_x.at(i), current_y.at(j), current_y.at(i));
    }

    auto result = std::vector<double>(y.size());
    for (int i = y.size() - 1; i >= 0; i--) {
        auto& currentVar = result.at(i);
        currentVar = current_y.at(i) / current_x.at(i).at(i);
        backSubstitution(current_x, current_y, i, currentVar);
    }

    return result;
}

int GaussianElimination::findIndexOfFirstRowWithNonNullEntryAt(
    const std::vector<std::vector<double>>& matrix,
    const unsigned int startPivotIndex
) const
{
    assert(startPivotIndex < matrix.size());

    for (auto r = startPivotIndex; r < matrix.size(); r++)
        if (matrix.at(r).at(startPivotIndex) != 0)
            return r;

    throw std::runtime_error("Redundant equations are not handled!");
    return -1;
}

void GaussianElimination::swapRows(
    std::vector<std::vector<double>> &matrix,
    std::vector<double>& y,
    const unsigned int r1,
    const unsigned int r2
) const
{
    assert(r1 < matrix.size() && r2 < matrix.size());
    assert(matrix.at(r1).size() == matrix.at(r2).size());

    std::swap(matrix.at(r1), matrix.at(r2));
    std::swap(y.at(r1), y.at(r2));
}

void GaussianElimination::linearTransformRow(
    std::vector<double> &x_row,
    const std::vector<double> &x_row_pivot,
    double &y_value,
    const double &y_pivot
) const
{
    auto pivot = 0.0;
    auto columnIndex = -1;
    for(auto it = x_row_pivot.begin(); it != x_row_pivot.end(); it++)
        if (*it != 0) {
            pivot = *it;
            columnIndex = std::distance(x_row_pivot.begin(), it);
            break;
        }

    if (columnIndex == -1 || pivot == 0.0)
        throw std::runtime_error("No pivot has been found in the given row");

    double factor = -x_row.at(columnIndex) / pivot;
    for (unsigned int i = 0; i < x_row_pivot.size(); i++)
        x_row.at(i) += factor * x_row_pivot.at(i);
    y_value += factor * y_pivot;
}

void GaussianElimination::backSubstitution(
    std::vector<std::vector<double>> &matrix,
    std::vector<double>& y,
    const unsigned int rowIndex,
    const double variableValue
) const
{
    assert(rowIndex < matrix.size());

    for (int i = rowIndex - 1; i >= 0; i--) {
        auto coeff = matrix.at(i).at(rowIndex);
        matrix.at(i).at(rowIndex) = 0.0;

        y.at(i) -= coeff * variableValue;
    }
}
