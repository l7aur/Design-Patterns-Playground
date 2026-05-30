#pragma once

#include "StreamDecorator.hpp"

class CharacterReplacer : public StreamDecorator
{
public:
    CharacterReplacer(
        std::unique_ptr<Stream> stream_,
        const char to_be_replaced_,
        const char replacer_
    );
    ~CharacterReplacer() override = default;

    Stream& operator<<(const std::string& str) override;

private:
    const char to_be_replaced;
    const char replacer;

    std::string replace(const std::string& str) const;
};