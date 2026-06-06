#pragma once

#include "MacroCommand.hpp"

class File;

class ReplaceAllCommand : public MacroCommand
{
public:
    ReplaceAllCommand(File* const file_, const char old_, const char c_);
    ~ReplaceAllCommand() override = default;

private:
    File* const file;
    const char old;
    const char c;
};