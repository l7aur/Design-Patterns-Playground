#pragma once

#include "Stream.hpp"

#include <memory>

class StreamDecorator : public Stream
{
public:
    StreamDecorator(std::unique_ptr<Stream> stream_);
    ~StreamDecorator() override = default;

    virtual Stream& operator<<(const std::string& str) override;

protected:
    std::unique_ptr<Stream> stream;
};