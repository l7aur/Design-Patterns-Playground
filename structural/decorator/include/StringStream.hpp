#pragma once

#include "Stream.hpp"

class StringStream : public Stream
{
public:
    ~StringStream() override = default;

    Stream& operator<<(const std::string& str);
};