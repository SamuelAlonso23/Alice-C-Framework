//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsUnionClass
        {
        public:
            constexpr static bool Value = __is_union(T);
        };

        template<class T> constexpr bool IsUnion = IsUnionClass<T>::Value;
    }
}