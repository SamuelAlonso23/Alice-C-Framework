//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Inline.hpp>

namespace Alice
{
    namespace BitConverter
    {
        AliceInline u32 U8ToU32(u8 First, u8 Second, u8 Third, u8 Forth) noexcept
        {
            return static_cast<u32>((First << 24u) | (Second << 16u) | (Third << 8u) | Forth);
        }
    }
}