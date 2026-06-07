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
    void unpaste();
    void navigate(const int index);
    void display();
    void save();
    char replace(const int where, const char c);
    int find_first(const char c, const int start = 0);
    int count(const char c);

private:
    std::filesystem::path filePath{};
    std::fstream fp{};
    int pointer{ 0 };
    std::vector<char> data{};
    std::vector<char> buffer{};
};