#pragma once

#include "AssetPrimitive.hpp"

class Investment : public AssetPrimitive
{
public:
    Investment(const std::string& name_, const money value_);
    ~Investment() override = default;

    virtual money getValue() const override;

private:
    const money value;
};