#pragma once

#include <list>
#include <memory>

class Command;

class CommandTracker
{
public:
    CommandTracker() = default;
    ~CommandTracker() = default;

    void add(std::unique_ptr<Command> cmd);
    void undo(const int howMany);
    void redo(const int howMany);

private:
    std::list<std::unique_ptr<Command>> commands{};
    std::list<std::unique_ptr<Command>>::const_iterator pointer{ commands.begin() };
};