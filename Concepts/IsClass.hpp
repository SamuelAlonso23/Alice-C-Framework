//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsClassClass
        {
        public:
            constexpr static bool Value = __is_class(T);
        };

        template<class T> constexpr bool IsClass = IsClassClass<T>::Value;
    }
}