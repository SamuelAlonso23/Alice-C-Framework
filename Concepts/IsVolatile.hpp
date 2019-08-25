//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class IsVolatile
        {
        public:
            constexpr static bool Value = false;
        };

        template<class T> class IsVolatile<volatile T>
        {
        public:
            constexpr static bool Value = true;
        };
    }
}