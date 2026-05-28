#pragma once

#include "AssetComposite.hpp"

class Portofolio : public AssetComposite
{
public:
    Portofolio(const std::string& name_, const int id_);
    ~Portofolio() override = default;
    virtual void print(std::ostream& out, const unsigned int indent = 0) override;

private:
    const int id;
};