//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic\Inline.hpp>
#include <Concepts\RemoveReferences.hpp>

namespace Alice
{
    template<class T> AliceInline T&& Forward(typename Alice::Concepts::RemoveReferences<T>::Type&& value) noexcept
    {
        return static_cast<T&&>(value);
    }
}