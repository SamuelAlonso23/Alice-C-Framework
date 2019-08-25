//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<bool Enable, class T = void> class EnableIf{};

        template<class T> class EnableIf<true, T>
        {
        public:
            typedef T Type;
        };
    }
}