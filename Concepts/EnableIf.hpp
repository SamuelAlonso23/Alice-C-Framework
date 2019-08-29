//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<bool Enable, class T = void> class EnableIfClass{};

        template<class T> class EnableIfClass<true, T>
        {
        public:
            typedef T Type;
        };

        template<bool Enable, class T = void> using EnableIf = typename EnableIfClass<Enable, T>::Type;
    }
}