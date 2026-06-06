#pragma once

#include "Command.hpp"

class File;

class NavigateCommand : public Command
{
public:
    NavigateCommand(
        File* const file_,
        const int howMany_
    );

    void execute() override;
    void undo() override;
    void redo() override;

private:
    File* file;
    const int howMany;
};