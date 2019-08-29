//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T, class V> class IsSameClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsSameClass<T, T>
        {
        public:
            constexpr static bool Value = true;
        };

        template<class T, class U> constexpr bool IsSame = IsSameClass<T, U>::Value;
    }
}