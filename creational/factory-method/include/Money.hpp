#pragma once

class Money
{
public:
    Money(int x) : value{x} {}
    virtual ~Money() = default;
    virtual int convertToRobux() const = 0;

protected:
    int value;
};