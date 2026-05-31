#include "StringStream.hpp"

#include <iostream>

Stream &StringStream::operator<<(const std::string &str)
{
    std::cout << str << std::endl;
    return *this;
}
