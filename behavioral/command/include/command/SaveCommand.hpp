#pragma once

#include "File.hpp"
#include "SimpleCommand.hpp"

class SaveCommand : public SimpleCommand<File>
{
public:
    SaveCommand(
        File* const file
    ) : SimpleCommand<File>(file, &File::save) { }
    ~SaveCommand() override = default;
};