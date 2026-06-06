#pragma once

#include "File.hpp"
#include "SimpleCommand.hpp"

class CloseCommand : public SimpleCommand<File>
{
public:
    CloseCommand(
        File* const f
    ) : SimpleCommand<File>(f, &File::close) { }
    ~CloseCommand() override = default;
};