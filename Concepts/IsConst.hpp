//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsConst
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsConst<const T>
        {
        public:
            constexpr static bool Value = true;
        };
    }
}