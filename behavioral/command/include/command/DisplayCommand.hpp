#pragma once

#include "SimpleCommand.hpp"

#include "File.hpp"

class DisplayCommand : public SimpleCommand<File>
{
public:
    DisplayCommand(
        File* const f
    ) : SimpleCommand<File>(f, &File::display) { }
};