//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<bool b, class T, class U> class ConditionalClass
        {
        public:
            typedef U Type;
        };

        template<class T, class U> class ConditionalClass<true, T, U>
        {
        public:
            typedef T Type;
        };

        template<bool b, class T, class U> using Conditional = typename ConditionalClass<b, T, U>::Type;
    }
}