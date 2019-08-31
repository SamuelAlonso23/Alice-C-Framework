//Copyright Alice Framework, All Rights Reserved
#pragma once

namespace Alice
{
    namespace Concepts
    {
        template<class T> class AddRvalueReferenceClass
        {
        public:
            typedef T&& Type;
        };

        template<class T> using AddRvalueReference = typename AddRvalueReferenceClass<T>::Type;
    }
}