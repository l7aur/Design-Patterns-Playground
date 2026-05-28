#pragma once

#include "Asset.hpp"

class AssetPrimitive : public Asset
{
public:
    ~AssetPrimitive() override = default;

    virtual money getValue() const = 0;
    virtual void add(std::unique_ptr<Asset> a) override;
    virtual void remove(const std::string& asset_name) override;
    virtual void print(std::ostream& out, const unsigned int indent = 0) override;

    virtual std::list<std::unique_ptr<Asset>>::const_iterator begin() const override;
    virtual std::list<std::unique_ptr<Asset>>::const_iterator end() const override;

protected:
    AssetPrimitive(const std::string& name_);

private:
    void unavailable_method() const;
};