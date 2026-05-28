#include "Loan.hpp"

Loan::Loan(
    const std::string& name_,
    const money value_
) : AssetPrimitive{ name_ }
  , value{ value_ }
{ }

money Loan::getValue() const
{
    return value;
}