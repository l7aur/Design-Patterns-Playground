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
    ~NavigateCommand() override = default;

    void execute() override;
    void undo() override;

private:
    File* const file;
    const int howMany;
};