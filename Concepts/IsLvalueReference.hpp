//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Concepts/IsSame.hpp>
#include <Concepts/RemoveConst.hpp>
#include <Concepts/RemoveVolatile.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsLvalueReferenceClass
        {
        public:
            constexpr static bool Value = IsSame<T&, RemoveConst<RemoveVolatile<T>>>;
        };

        template<class T> constexpr bool IsLvalueReference = IsLvalueReferenceClass<T>::Value;
    }
}