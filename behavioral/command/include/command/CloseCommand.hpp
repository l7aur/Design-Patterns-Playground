#pragma once

#include "SimpleCommand.hpp"

#include "File.hpp"

class CloseCommand : public SimpleCommand<File>
{
public:
    CloseCommand(
        File* const f
    ) : SimpleCommand<File>(f, &File::close) { }
};