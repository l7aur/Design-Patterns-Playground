#pragma once

#include <filesystem>
#include <list>

struct FileSystemEntity {
    FileSystemEntity(const std::filesystem::path& p) : path{p}, entities{} {
        if (!std::filesystem::is_directory(path)) {
            return;
        }

        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            entities.push_back(FileSystemEntity(entry.path()));
        }
    }

    std::list<FileSystemEntity> entities;
    std::filesystem::path path;
};
