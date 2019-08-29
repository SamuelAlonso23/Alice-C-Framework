//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Inline.hpp>
#include <Concepts\IsSame.hpp>
#include <Concepts\RemoveConst.hpp>
#include <Concepts\RemoveVolatile.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> AliceInline constexpr bool IsPureVoidFunc() noexcept
        {
            return IsSame<T, void>;
        }

        template<class T> AliceInline constexpr bool IsConstVoidFunc() noexcept
        {
            return IsSame<RemoveConst<T>, void>;
        }

        template<class T> AliceInline constexpr bool IsVolatileVoidFunc() noexcept
        {
            return IsSame<RemoveVolatile<T>, void>;
        }

        template<class T> AliceInline constexpr bool IsVoidFunc() noexcept
        {
            return IsSame<RemoveConst<RemoveVolatile<T>>, void>;
        }

        template<class T> constexpr bool IsPureVoid = IsPureVoidFunc<T>();

        template<class T> constexpr bool IsConstVoid = IsConstVoidFunc<T>();

        template<class T> constexpr bool IsVolatileVoid = IsVolatileVoidFunc<T>();

        template<class T> constexpr bool IsVoid = IsVoidFunc<T>();
    }
}