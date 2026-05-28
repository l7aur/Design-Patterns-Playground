#pragma once

#include "Asset.hpp"

class AssetPrimitive : public Asset
{
public:
    ~AssetPrimitive() override = default;

    virtual money getValue() const = 0;
    virtual void add(std::unique_ptr<Asset> a) override
        { unavailable_method(); }
    virtual void remove(const std::string& assetName) override
        { unavailable_method(); }
    virtual void print(std::ostream& out, const unsigned int indent = 0) override
        { out << std::string(indent, ' ') <<  "Asset name: \"" << getName() << "\" of value: " << getValue() << "\n"; }

    virtual std::list<std::unique_ptr<Asset>>::const_iterator begin() const override
        { unavailable_method(); return std::list<std::unique_ptr<Asset>>::const_iterator(); }
    virtual std::list<std::unique_ptr<Asset>>::const_iterator end() const override
        { unavailable_method(); return std::list<std::unique_ptr<Asset>>::const_iterator(); }
protected:
    AssetPrimitive(const std::string& name_) : Asset{ name_ } {}

private:
    void unavailable_method() const
        { throw std::runtime_error("Invalid operation attempted on primitive asset!"); }
};