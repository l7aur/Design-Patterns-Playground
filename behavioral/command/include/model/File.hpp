#pragma once

#include <string>
#include <fstream>
#include <filesystem>

class File
{
public:
    File();
    ~File() = default;

    void open(const std::filesystem::path& p);
    void close();
    void copy(const int howMany);
    void paste();
    void navigate(const int index);
    void display();
    void save();

private:
    std::fstream fp{};
    int pointer{ 0 };
    std::vector<char> data{};
    std::vector<char> buffer{};
};