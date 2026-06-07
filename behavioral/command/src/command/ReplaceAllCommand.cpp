#include "ReplaceAllCommand.hpp"
#include "ReplaceFirstCommand.hpp"

#include "File.hpp"

ReplaceAllCommand::ReplaceAllCommand(
    File* const file_,
    const char old_,
    const char c_
)   : file{ file_ }
    , old{ old_ }
    , c{ c_ }
{
    auto howMany = file->count(old);
    for (int i = 0; i < howMany; i++)
        add(std::make_unique<ReplaceFirstCommand>(file, old, c));
}