#pragma once

#include <string>

class StreamDecorator;

class Stream
{
public:
    virtual ~Stream() = default;

    virtual Stream& operator<<(const std::string& str) = 0;
};