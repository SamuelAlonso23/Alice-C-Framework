//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class RemoveVolatileClass
        {
        public:
            typedef T Type;
        };

        template<class T> class RemoveVolatileClass<volatile T>
        {
        public:
            typedef T Type;
        };

        template<class T> using RemoveVolatile = typename RemoveVolatileClass<T>::Type;
    }
}