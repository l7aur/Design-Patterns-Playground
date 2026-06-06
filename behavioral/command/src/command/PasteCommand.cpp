#include "PasteCommand.hpp"

#include "File.hpp"

PasteCommand::PasteCommand(File* const file)
    : SimpleCommand<File>(file, &File::paste)
{ }

void PasteCommand::undo()
{
    receiver->unpaste();
}
