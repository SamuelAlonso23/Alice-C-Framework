//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts\IsSame.hpp>
#include <Concepts\RemoveConst.hpp>
#include <Concepts\RemoveVolatile.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsNullPtrTypeClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveConst<RemoveVolatile<T>>, decltype(nullptr)>;
        };

        template<class T> class IsConstNullPtrTypeClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveConst<T>, decltype(nullptr)>;
        };

        template<class T> class IsVolatileNullPtrTypeClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveVolatile<T>, decltype(nullptr)>;
        };

        template<class T> class IsPureNullPtrTypeClass
        {
        public:
            constexpr static bool Value = IsSame<T, decltype(nullptr)>;
        };

        template<class T> constexpr bool IsNullPtrType = IsNullPtrTypeClass<T>::Value;

        template<class T> constexpr bool IsConstNullPtrType = IsConstNullPtrTypeClass<T>::Value;

        template<class T> constexpr bool IsVolatileNullPtrType = IsVolatileNullPtrTypeClass<T>::Value;

        template<class T> constexpr bool IsPureNullPtrType = IsPureNullPtrTypeClass<T>::Value;
    }
}