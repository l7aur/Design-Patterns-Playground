#include "AssetComposite.hpp"

#include <algorithm>

AssetComposite::AssetComposite(
    const std::string& name_
) : Asset{ name_ }
{ }

void AssetComposite::add(
    std::unique_ptr<Asset> a
)
{
    assets.push_back(std::move(a));
}

void AssetComposite::remove(
    const std::string& asset_name
)
{
    assets.remove_if([&asset_name] (const auto& ptr) {
        return ptr->getName() == asset_name;
    });
}

void AssetComposite::print(std::ostream &out, const unsigned int indent)
{
    out << "Asset name: \"" << getName() << "\" of value: " << getValue() << "\n";
    for (const auto& a : assets)
        a->print(out, indent + 2);
}

money AssetComposite::getValue() const
{
    money total_value = 0;
    for (const auto& a : assets)
        total_value += a->getValue();
    return total_value;
}

std::list<std::unique_ptr<Asset>>::const_iterator AssetComposite::begin() const
{
    return assets.begin();
}

std::list<std::unique_ptr<Asset>>::const_iterator AssetComposite::end() const
{
    return assets.end();
}