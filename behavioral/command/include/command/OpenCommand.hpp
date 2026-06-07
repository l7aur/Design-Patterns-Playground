#pragma once

#include "Command.hpp"

#include <filesystem>

class File;

class OpenCommand : public Command
{
public:
    OpenCommand(
        File* const file_,
        const std::filesystem::path& p_
    );
    ~OpenCommand() override = default;

    void execute() override;
    void undo() override;

private:
    File* const file;
    const std::filesystem::path p;
};