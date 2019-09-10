//Copyright Alice Framework, All Rights Reserved
#pragma once

/** @file AddConstVolatile.hpp 
 *  
 */

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddConstVolatileClass
        {
        public:
            typedef const volatile T Type;
        };

        template<class T> using AddConstVolatile = typename AddConstVolatileClass<T>::Type;
    }
}