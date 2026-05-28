#include "Investment.hpp"

Investment::Investment(
    const std::string& name_,
    const money value_
) : AssetPrimitive{ name_ }
  , value{value_ }
{ }

money Investment::getValue() const
{
    return value;
}

