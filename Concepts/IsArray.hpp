//Copyright Alice Framework, All Rights Reserved
#pragma once
#include <Basic/Types.hpp>

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsArrayClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsArrayClass<T[]>
        {
        public:
            constexpr static bool Value = true;
        };

        template<class T, u64 Size> class IsArrayClass<T[Size]>
        {
        public:
            constexpr static bool Value = true;
        };

        template<class T> constexpr bool IsArray = IsArrayClass<T>::Value;
    }
}