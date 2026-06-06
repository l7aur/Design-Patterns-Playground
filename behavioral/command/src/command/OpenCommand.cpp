#include "OpenCommand.hpp"

#include "File.hpp"

OpenCommand::OpenCommand(
    File *const file_,
    const std::filesystem::path &p_
)   : file{ file_ }
    , p{ p_ }
{ }

void OpenCommand::execute()
{
    file->open(p);
}

void OpenCommand::undo()
{
}

void OpenCommand::redo()
{
}