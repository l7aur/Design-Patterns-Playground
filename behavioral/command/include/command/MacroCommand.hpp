#pragma once

#include "Command.hpp"

#include <list>
#include <memory>

class MacroCommand : public Command
{
public:
    virtual ~MacroCommand() override = default;

    void add(std::unique_ptr<Command> cmd);
    void pop_front();
    void pop_back();
    Command* back() const;
    virtual void execute() override;
    virtual void undo() override;
    virtual void redo() override;

protected:
    MacroCommand() = default;

private:
    std::list<std::unique_ptr<Command>> commands{};
};