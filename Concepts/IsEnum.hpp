//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsEnumClass
        {
        public:
            constexpr static bool Value = __is_enum(T);
        };

        template<class T> constexpr bool IsEnum = IsEnumClass<T>::Value;
    }
}