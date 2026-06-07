#pragma once

#include "File.hpp"
#include "SimpleCommand.hpp"

class DisplayCommand : public SimpleCommand<File>
{
public:
    DisplayCommand(
        File* const f
    ) : SimpleCommand<File>(f, &File::display) { }
    ~DisplayCommand() override = default;
};