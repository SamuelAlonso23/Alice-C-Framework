//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Core\Exception.hpp>

namespace Alice
{
    namespace Limits
    {
        template<class T> AliceInline T Min() noexcept
        {
            Exception::Raise(ExceptionType::TypeNotSupported);
            return T();
        }

        template<class T> AliceInline T Max() noexcept
        {
            Exception::Raise(ExceptionType::TypeNotSupported);
            return T();
        }

        template<> AliceInline bool Min<bool>() noexcept
        {
            return false;
        }

        template<> AliceInline bool Max<bool>() noexcept
        {
            return true;
        }

        template<> AliceInline u8 Min<u8>() noexcept
        {
            return 0u;
        }

        template<> AliceInline u8 Max<u8>() noexcept
        {
            return 255u;
        }

        template<> AliceInline s8 Min<s8>() noexcept
        {
            return -128;
        }

        template<> AliceInline s8 Max<s8>() noexcept
        {
            return 127;
        }

        template<> AliceInline u16 Min<u16>() noexcept
        {
            return 0u;
        }

        template<> AliceInline u16 Max<u16>() noexcept
        {
            return 65535u;
        }

        template<> AliceInline s16 Min<s16>() noexcept
        {
            return -32768;
        }

        template<> AliceInline s16 Max<s16>() noexcept
        {
            return 32767;
        }

        template<> AliceInline u32 Min<u32>() noexcept
        {
            return 0u;
        }

        template<> AliceInline u32 Max<u32>() noexcept
        {
            return 4294967295u;
        }

        template<> AliceInline s32 Min<s32>() noexcept
        {
            return -2147483648;
        }

        template<> AliceInline s32 Max<s32>() noexcept
        {
            return 2147483647;
        }

        template<> AliceInline f32 Min<f32>() noexcept
        {
            return 1.175494351e-38f;
        }

        template<> AliceInline f32 Max<f32>() noexcept
        {
            return 3.402823466e+38f;
        }

        template<> AliceInline u64 Min<u64>() noexcept
        {
            return 0u;
        }

        template<> AliceInline u64 Max<u64>() noexcept
        {
            return 18446744073709551615u;
        }

        template<> AliceInline s64 Min<s64>() noexcept
        {
            return -9223372036854775807;
        }

        template<> AliceInline s64 Max<s64>() noexcept
        {
            return 9223372036854775807;
        }

        template<> AliceInline f64 Min<f64>() noexcept
        {
            return 2.2250738585072014e-308;
        }

        template<> AliceInline f64 Max<f64>() noexcept
        {
            return 1.7976931348623158e+308;
        }
    }
}