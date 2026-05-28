#include "AssetPrimitive.hpp"

AssetPrimitive::AssetPrimitive(
    const std::string &name_
) : Asset{ name_ }
{ }

void AssetPrimitive::add(
    std::unique_ptr<Asset> a
)
{
    unavailable_method();
}

void AssetPrimitive::remove(
    const std::string& asset_name
)
{
    unavailable_method();
}

void AssetPrimitive::print(
    std::ostream &out,
    const unsigned int indent)
{
    out << std::string(indent, ' ')
        <<  "Asset name: \"" << getName()
        << "\" of value: " << getValue() << "\n";
}

std::list<std::unique_ptr<Asset>>::const_iterator AssetPrimitive::begin() const
{
    unavailable_method();
    return std::list<std::unique_ptr<Asset>>::const_iterator();
}

std::list<std::unique_ptr<Asset>>::const_iterator AssetPrimitive::end() const
{
    unavailable_method();
    return std::list<std::unique_ptr<Asset>>::const_iterator();
}

void AssetPrimitive::unavailable_method() const
{
    throw std::runtime_error("Invalid operation attempted on primitive asset!");
}
