#include "NavigateCommand.hpp"
#include "File.hpp"

NavigateCommand::NavigateCommand(
    File *const file_,
    const int howMany_
)   : file{ file_ }
    , howMany{ howMany_ }
{ }

void NavigateCommand::execute()
{
    file->navigate(howMany);
}

void NavigateCommand::undo()
{
}

void NavigateCommand::redo()
{
}