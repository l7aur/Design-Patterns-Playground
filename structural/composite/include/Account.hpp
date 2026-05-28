#pragma once

#include "AssetComposite.hpp"

class Account : public AssetComposite
{
public:
    Account(const std::string& name_, const int owner_id_);
    ~Account() override = default;
    virtual void print(std::ostream& out, const unsigned int indent = 0) override;

private:
    const int owner_id;
};