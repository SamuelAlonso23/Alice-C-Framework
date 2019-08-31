//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddVolatileClass
        {
        public:
            typedef volatile T Type;
        };

        template<class T> using AddVolatile = typename AddVolatileClass<T>::Type;
    }   
}