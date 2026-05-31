#pragma once

#include "StreamDecorator.hpp"

class Compresser : public StreamDecorator
{
public:
    Compresser(std::unique_ptr<Stream> stream_);
    ~Compresser() override = default;

    Stream& operator<<(const std::string& str) override;

private:
    std::string compress(const std::string& str) const;
};