#pragma once

#include "Command.hpp"

class MacroCommand : public Command
{
public:
    virtual ~MacroCommand() override = default;

    virtual void execute();
    virtual void undo();
    virtual void redo();

protected:
    MacroCommand();
};