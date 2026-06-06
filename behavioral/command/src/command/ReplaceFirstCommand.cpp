#include "ReplaceFirstCommand.hpp"

#include "File.hpp"

ReplaceFirstCommand::ReplaceFirstCommand(File* const file_, const char old_, const char c_)
    : file{ file_ }
    , old{ old_ }
    , c{ c_ }
{ }

void ReplaceFirstCommand::execute()
{
    index = file->find_first(c);
    old = file->replace(index, c);
}

void ReplaceFirstCommand::undo()
{
    file->replace(index, old);
}