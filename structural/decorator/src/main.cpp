#include "StringStream.hpp"
#include "Compresser.hpp"
#include "CharacterReplacer.hpp"

int main(int argc, char* argv[])
{
    std::string str = "aaaabbaaabbbbccccaaaa";

    CharacterReplacer(std::make_unique<StringStream>(), 'a', 'x') << str << str;
    Compresser(std::make_unique<StringStream>()) << str << str;
    Compresser(std::make_unique<CharacterReplacer>(std::make_unique<StringStream>(), '#', 'x')) << str << str;
    CharacterReplacer(std::make_unique<Compresser>(std::make_unique<StringStream>()), '#', 'x') << str << str;

    return 0;
}