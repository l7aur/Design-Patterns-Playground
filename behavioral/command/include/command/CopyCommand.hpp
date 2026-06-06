#pragma once

#include "Command.hpp"

class File;

class CopyCommand : public Command
{
public:
    CopyCommand(
        File* const file_,
        const size_t howMany_
    );

    void execute() override;
    void undo() override;
    void redo() override;

private:
    File* const file;
    const size_t howMany;
};