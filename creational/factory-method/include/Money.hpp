#pragma once

class Money
{
public:
    Money(int x) : value{x} {}
    virtual int convertToRobux() const = 0;

protected:
    int value;
};