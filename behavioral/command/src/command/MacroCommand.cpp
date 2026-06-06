#include "MacroCommand.hpp"

void MacroCommand::add(std::unique_ptr<Command> cmd)
{
    commands.push_back(std::move(cmd));
}

void MacroCommand::pop_front()
{
    commands.pop_front();
}

void MacroCommand::pop_back()
{
    commands.pop_back();
}

Command *MacroCommand::back() const
{
    return commands.back().get();
}

void MacroCommand::execute()
{
    for (const auto& cmd : commands)
        cmd->execute();
}

void MacroCommand::undo()
{
    for (auto it = commands.rend(); it != commands.rbegin(); it++)
        (*it)->undo();   
}

void MacroCommand::redo()
{
    for (const auto& cmd : commands)
        cmd->redo();
}