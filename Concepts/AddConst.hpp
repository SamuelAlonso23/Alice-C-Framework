//Copyright Alice Framework, All Rights Reserved
#pragma once

/** @file AddConst.hpp */

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddConstClass
        {
        public:
            typedef const T Type;
        };

        template<class T> using AddConst = typename AddConstClass<T>::Type;
    }
}