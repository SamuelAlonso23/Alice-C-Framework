//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts/EnableIf.hpp>
#include <Concepts/IsConvertible.hpp>

namespace Alice
{
    template<class T> class DefaultDelete
    {
    public:
        AliceInline constexpr DefaultDelete() noexcept{}

        template<class U, class = requires Concepts::IsConvertible<U*, T*>> AliceInline DefaultDelete(const DefaultDelete<U>&) noexcept{}

        AliceInline void operator()(T* ptr) const noexcept
        {
            static_assert(!Concepts::IsVoid<T>, "Cannot delete pointer of an incomplete type");
            static_assert(sizeof(T) > 0, "Cannot delete pointer of an incomplete type");
            delete ptr;
        }
    };

    template<class T> class DefaultDelete<T[]>
    {
    public:
        AliceInline constexpr DefaultDelete() noexcept{}

        template<class U, class = requires Concepts::IsConvertible<U(*)[], T(*)[]>> AliceInline DefaultDelete(const DefaultDelete<U[]>&) noexcept{}

        template<class U, class Concepts::EnableIf<Concepts::IsConvertible<U(*)[], T(*)[]>::Type>> AliceInline operator()(U* ptr) const noexcept
        {
            static_assert(sizeof(T) > 0, "Cannot delete pointer of an incomplete type");
            delete[] ptr;
        }
    };
}