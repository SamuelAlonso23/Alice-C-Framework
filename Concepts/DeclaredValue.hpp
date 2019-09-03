//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Inline.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> AliceInline T&& DeclaredValueFunc(int) noexcept{}

        template<class T> AliceInline T DeclaredValueFunc(long) noexcept{}

        template<class T> AliceInline auto DeclaredValue() noexcept -> decltype(DeclaredValueFunc<T>(0)){}
    }
}