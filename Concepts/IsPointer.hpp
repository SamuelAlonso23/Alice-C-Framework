//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsPointerClass
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsPointerClass<T*>
        {
        public:
            constexpr static bool Value = true;
        };

        template<class T> constexpr bool IsPointer = IsPointerClass<T>::Value;
    }
}