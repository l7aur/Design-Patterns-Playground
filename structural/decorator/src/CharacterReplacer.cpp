#include "CharacterReplacer.hpp"

CharacterReplacer::CharacterReplacer(
    std::unique_ptr<Stream> stream_,
    const char to_be_replaced_,
    const char replacer_
) : StreamDecorator{ std::move(stream_) }
  , to_be_replaced{ to_be_replaced_ }
  , replacer{ replacer_ }
{ }

Stream &CharacterReplacer::operator<<(const std::string &str)
{
    auto new_str = replace(str);
    StreamDecorator::operator<<(new_str);
    return *this;
}

std::string CharacterReplacer::replace(const std::string &str) const
{
    std::string s{ "" };

    for (const auto& i : str) {
        s.append(std::string(i == to_be_replaced ? &replacer : &i, sizeof(char)));
    }

    return s;
}
