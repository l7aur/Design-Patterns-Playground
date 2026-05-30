#include "Compresser.hpp"

Compresser::Compresser(std::unique_ptr<Stream> stream_)
    : StreamDecorator{ std::move(stream_) }
{ }

Stream &Compresser::operator<<(const std::string &str)
{
    *stream << compress(str);
    return *this;
}

std::string Compresser::compress(const std::string &str) const
{
    if (str.empty())
        return str;

    std::string s{ "" };
    auto last_char = str.front();
    int c = 0;
    for (const auto& i : str) {
        if (last_char == i)
            c++;
        else {
            s.append(std::string(&last_char, 1))
             .append("#")
             .append(std::to_string(c));
            last_char = i;
            c = 1;
        }
    }

    return s.append(std::string(&last_char, 1))
            .append("#")
            .append(std::to_string(c));
}
