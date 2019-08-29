//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsConstClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsConstClass<const T>
        {
        public:
            constexpr static bool Value = true;
        };

        template<typename T> constexpr bool IsConst = IsConstClass<T>::Value;
    }
}