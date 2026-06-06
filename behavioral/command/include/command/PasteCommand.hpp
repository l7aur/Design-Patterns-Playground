#pragma once

#include "SimpleCommand.hpp"

#include "File.hpp"

class PasteCommand : public SimpleCommand<File>
{
public:
    PasteCommand(
        File* const file
    ) : SimpleCommand<File>(file, &File::paste) { }
};