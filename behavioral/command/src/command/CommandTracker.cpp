#include "CommandTracker.hpp"

#include "Command.hpp"

void CommandTracker::add(std::unique_ptr<Command> cmd)
{
    if (!commands.empty() && pointer != std::prev(commands.end()))
        commands.erase(std::next(pointer), commands.end());

    commands.push_back(std::move(cmd));
    pointer = std::prev(commands.end());
}

void CommandTracker::undo(const int howMany)
{
    for (int i = 0; i < howMany; i++) {
        (*pointer)->undo();
        if (pointer == commands.begin())
            break;
        --pointer;
    }
}

void CommandTracker::redo(const int howMany)
{
    for (int i = 0; i < howMany; i++) {
        ++pointer;
        (*pointer)->redo();
        if (std::next(pointer) == commands.end())
            break;
    }
}
