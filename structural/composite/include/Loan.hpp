#pragma once

#include "AssetPrimitive.hpp"

class Loan : public AssetPrimitive
{
public:
    Loan(const std::string& name_, const money value_);
    ~Loan() override = default;

    virtual money getValue() const override;

private:
    const money value;
};