//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts\IsSame.hpp>
#include <Concepts\RemoveConst.hpp>
#include <Concepts\RemoveVolatile.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsPureVoidClass
        {
        public:
            constexpr static bool Value = IsSame<T, void>;
        };

        template<class T> class IsConstVoidClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveConst<T>, void>;
        };

        template<class T> class IsVolatileVoidClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveVolatile<T>, void>;
        };

        template<class T> class IsVoidClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveConst<RemoveVolatile<T>>, void>;
        };

        template<class T> constexpr bool IsPureVoid = IsPureVoidClass<T>::Value;

        template<class T> constexpr bool IsConstVoid = IsConstVoidClass<T>::Value;

        template<class T> constexpr bool IsVolatileVoid = IsVolatileVoidClass<T>::Value;

        template<class T> constexpr bool IsVoid = IsVoidClass<T>::Value;
    }
}