//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddLvalueReferenceClass
        {
        public:
            typedef T& Type;
        };

        template<class T> using AddLvalueReference = typename AddLvalueReferenceClass<T>::Type;
    }
}