#include "StreamDecorator.hpp"

StreamDecorator::StreamDecorator(std::unique_ptr<Stream> stream_)
    : stream{ std::move(stream_) }
{ }

Stream &StreamDecorator::operator<<(const std::string &str)
{
    *stream << str;
    return *this;
}
