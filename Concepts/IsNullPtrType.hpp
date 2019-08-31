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

        template<class T> constexpr bool IsNullPtrType = IsNullPtrTypeClass<T>::Value;
    }
}