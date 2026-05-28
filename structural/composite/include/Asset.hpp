#pragma once

#include "Types.hpp"

#include <list>
#include <string>
#include <memory>
#include <iterator>
#include <stdexcept>
#include <iostream>

class Asset {
public:
    virtual ~Asset() = default;

    std::string getName() const { return name; }

    virtual money getValue() const = 0;
    virtual void add(std::unique_ptr<Asset> a) = 0;
    virtual void remove(const std::string& assetName) = 0;
    virtual void print(std::ostream& out, const unsigned int indent = 0) = 0;

    virtual std::list<std::unique_ptr<Asset>>::const_iterator begin() const = 0;
    virtual std::list<std::unique_ptr<Asset>>::const_iterator end() const = 0;

protected:
    explicit Asset(const std::string& name_) : name{ name_ } {}

private:
    const std::string name;
};