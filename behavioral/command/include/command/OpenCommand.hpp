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

    void execute() override;
    void undo() override;
    void redo() override;

private:
    File* const file;
    const std::filesystem::path p;
};