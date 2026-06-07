#pragma once

#include "File.hpp"
#include "SimpleCommand.hpp"

class PasteCommand : public SimpleCommand<File>
{
public:
    PasteCommand(
        File* const file
    );
    ~PasteCommand() override = default;

    void undo() override;
};