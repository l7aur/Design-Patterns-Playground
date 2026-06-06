#include "CopyCommand.hpp"

#include "File.hpp"

CopyCommand::CopyCommand(
    File* const file_,
    const size_t howMany_
)   : file{ file_ }
    , howMany{ howMany_ }
{ }

void CopyCommand::execute()
{
    file->copy(howMany);
}

void CopyCommand::undo()
{
}

void CopyCommand::redo()
{
}