#pragma once

#include "SimpleCommand.hpp"

class File;

class PasteCommand : public SimpleCommand<File>
{
public:
    PasteCommand(
        File* const file
    );
    ~PasteCommand() override = default;

    void undo() override;
};