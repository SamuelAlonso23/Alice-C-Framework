//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T, class V> class IsSame
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsSame<T, T>
        {
        public:
            constexpr static bool Value = true;
        };
    }
}