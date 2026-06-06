#pragma once

#include "Command.hpp"

class File;

class ReplaceFirstCommand : public Command
{
public:
    ReplaceFirstCommand(File* file_, const char old_, const char c_);
    ~ReplaceFirstCommand() override = default;

    int getIndex() const { return index; }
    void execute() override;
    void undo() override;

private:
    File* const file;
    const char c;
    char old{ 0 };
    int index{ -1 };
};