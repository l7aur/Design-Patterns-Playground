#include "File.hpp"

#include <iostream>
#include <algorithm>

File::File()
{ }

void File::open(const std::filesystem::path &p)
{
    fp.open(p, std::ios_base::in | std::ios_base::out);

    if (!fp.is_open())
        throw std::runtime_error("Failed to open file!");

    fp.seekg(0, std::ios_base::end);
    std::size_t file_size = fp.tellg();
    data.resize(file_size);
    fp.seekg(0, std::ios_base::beg);

    if (file_size > 0)
        fp.read(data.data(), file_size);
}

void File::close()
{
    fp.close();
}

void File::copy(const int howMany)
{
    buffer.resize(howMany);

    for (auto i = 0; i < howMany; i++)
        buffer.at(i) = data.at(i + pointer);
}

void File::paste()
{
    data.resize(buffer.size() + data.size());
    for (int i = data.size() - 1; i >= (std::max)(pointer, static_cast<int>(buffer.size())); i--)
        data.at(i) = data.at(i - buffer.size());

    for (auto i = 0; i < buffer.size(); i++)
        data.at(pointer + i) = buffer.at(i);

    pointer += buffer.size();
}

void File::navigate(const int index)
{
    pointer += index;
    if (pointer < 0)
        pointer = 0;
    if (pointer > data.size() - 1)
        pointer = data.size() - 1;
}

void File::display()
{
    for (const auto& c : data)
        std::cout << c;
    std::cout << std::endl;
}

void File::save()
{
    fp.seekp(0);
    fp.write(data.data(), data.size());
}
