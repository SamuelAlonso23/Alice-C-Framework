//Copyright Alice Framework, All Rights Reserved
#pragma once

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

        template<class T> constexpr bool IsArray = IsArrayClass<T>::Value;
    }
}