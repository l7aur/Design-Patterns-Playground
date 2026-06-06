#include "File.hpp"

#include <iostream>
#include <algorithm>

File::File()
{ }

void File::open(const std::filesystem::path &p)
{
    if (fp.is_open())
        fp.close();

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

void File::unpaste()
{
    pointer -= buffer.size();

    for (int i = pointer; i < data.size(); i++)
        data.at(i) = data.at(i + buffer.size());

    data.resize(data.size() - buffer.size());
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

char File::replace(const int where, const char c)
{
    if (where < 0 || where >= data.size())
        throw std::runtime_error("Where are you trying to replace?");

    auto old = data.at(where);
    data.at(where) = c;

    return old;
}

int File::find_first(const char c, const int start)
{
    if (start >= data.size())
        throw std::runtime_error("Where are you trying to find_first?");

    for (auto it = std::next(data.begin(), start); it != data.end(); it++)
        if (c == *it)
            return std::distance(data.begin(), it);
    return -1;
}

int File::count(const char c)
{
    int cnt = 0;
    for (const auto& ch : data)
        if (c == ch)
            cnt++;
    return cnt;
}
