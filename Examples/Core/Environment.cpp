#include <Core/Environment.hpp>

//returns memory page size in bytes
s32 MemoryPageSizeTest()
{
    return Alice::Environment::MemoryPageSize();
}