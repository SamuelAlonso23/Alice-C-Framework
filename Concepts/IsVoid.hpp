//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts/IsSame.hpp>
#include <Concepts/RemoveConst.hpp>
#include <Concepts/RemoveVolatile.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsVoidClass
        {
        public:
            constexpr static bool Value = IsSame<RemoveConst<RemoveVolatile<T>>, void>;
        };

        template<class T> constexpr bool IsVoid = IsVoidClass<T>::Value;
    }
}