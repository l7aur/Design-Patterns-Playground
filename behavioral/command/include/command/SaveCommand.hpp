#pragma once

#include "SimpleCommand.hpp"

#include "File.hpp"

class SaveCommand : public SimpleCommand<File>
{
public:
    SaveCommand(
        File* const file
    ) : SimpleCommand<File>(file, &File::save) { }
};