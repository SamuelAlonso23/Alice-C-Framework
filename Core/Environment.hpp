//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <OS.hpp>
#include <Basic\Types.hpp>
#include <Basic\Inline.hpp>

namespace Alice
{
    namespace Environment
    {
        AliceInline s32 MemoryPageSize() noexcept
        {
            #if defined(AliceWindows)
            SYSTEM_INFO si;
            GetSystemInfo(&si);
            return si.dwPageSize;
            #endif
        }
    }
}